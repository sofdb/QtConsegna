#include "UI/headers/productfilters.h"
#include "logic/headers/scala3converters.h"

namespace {
    template <typename T>
    void filterByNameContains(const QVector<T*>& list, const QString& searchText, QList<NailsProduct*>& risultati) {
        for (auto* p : list) {
            if (QString::fromStdString(p->getName()).contains(searchText, Qt::CaseInsensitive)) {
                risultati.append(p);
            }
        }
    }
}

QList<NailsProduct*> ProductFilters::filtra(
    const Catalogo& catalogo,
    const QString& searchText,
    const QString& tipoProdotto,
    const QString& color,
    const QString& finish,
    const QString& elasticity,
    const QString& grip,
    const QString& tbType,
    const QString& coverage,
    const QString& viscosity)
{
    QList<NailsProduct*> risultati;
    QString tipoProdottoEffettivo = tipoProdotto;

    if (tipoProdottoEffettivo.isEmpty() || tipoProdottoEffettivo == "Tutti") {
        if (!color.isEmpty() && color != "Tutti") {
            tipoProdottoEffettivo = "Smalto Semipermanente";
        } else if ((!finish.isEmpty() && finish != "Tutti") ||
                   (!elasticity.isEmpty() && elasticity != "Tutti") ||
                   (!grip.isEmpty() && grip != "Tutti") ||
                   (!tbType.isEmpty() && tbType != "Tutti")) {
            tipoProdottoEffettivo = "Top/Base";
        } else if ((!coverage.isEmpty() && coverage != "Tutti") ||
                   (!viscosity.isEmpty() && viscosity != "Tutti")) {
            tipoProdottoEffettivo = "Gel Costruttore";
        }
    }

    if (tipoProdottoEffettivo == "Smalto Semipermanente") {
        QList<SmaltoSemip*> result;
        if (!color.isEmpty() && color != "Tutti") {
            SemiColor col = SmaltoSemip::StringToSemicolor(color.toStdString());
            result = catalogo.filterSmaltoByColor(col);
        } else {
        result = catalogo.getSmaltoSemip();
        }
        filterByNameContains(result, searchText, risultati);

    } else if (tipoProdottoEffettivo == "Top/Base") {
        std::optional<Finish> f = (finish != "Tutti" && !finish.isEmpty()) ? std::make_optional(TopBase::StringToFinish(finish.toStdString())) : std::nullopt;
        std::optional<Scala3> el = (elasticity != "Tutti" && !elasticity.isEmpty()) ? std::make_optional(Scala3Converters::StringToScala3(elasticity.toStdString())) : std::nullopt;
        std::optional<Scala3> gr = (grip != "Tutti" && !grip.isEmpty()) ? std::make_optional(Scala3Converters::StringToScala3(grip.toStdString())) : std::nullopt;
        std::optional<TopBaseType> tb = (tbType != "Tutti" && !tbType.isEmpty()) ? std::make_optional(TopBase::StringToTBtype(tbType.toStdString())) : std::nullopt;

        auto result = catalogo.filterTopBase(f, el, gr, tb);
        filterByNameContains(result, searchText, risultati);

    } else if (tipoProdottoEffettivo == "Gel Costruttore") {
        std::optional<Scala3> cov = (coverage != "Tutti" && !coverage.isEmpty()) ? std::make_optional(Scala3Converters::StringToScala3(coverage.toStdString())) : std::nullopt;
        std::optional<Scala3> vis = (viscosity != "Tutti" && !viscosity.isEmpty()) ? std::make_optional(Scala3Converters::StringToScala3(viscosity.toStdString())) : std::nullopt;

        auto result = catalogo.filterGelCostruttore(cov, vis, std::nullopt, std::nullopt);
        filterByNameContains(result, searchText, risultati);

    } else {
        auto all = catalogo.getAllProducts();
        filterByNameContains(all, searchText, risultati);
    }

    return risultati;
}
