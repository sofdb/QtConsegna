#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "UI/headers/nailsproductvisitor.h"

#include <QJsonObject>

class JsonVisitor : public NailsProductVisitor
{
private:
    QJsonObject jsonProduct;

public:
    QJsonObject getJsonProduct() const;
    void visit(const SmaltoSemip& prod) override;
    void visit(const TopBase& prod) override;
    void visit(const GelCostruttore& prod) override;
};

#endif // JSONVISITOR_H

