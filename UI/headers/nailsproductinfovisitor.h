#ifndef NAILSPRODUCTINFOVISITOR_H
#define NAILSPRODUCTINFOVISITOR_H

#include <QWidget>

#include "UI/headers/nailsproductvisitor.h"

class NailsProductInfoVisitor : public NailsProductVisitor
{
private:
    QWidget* widget;
public:
    QWidget* getWidget();

    void visit(const SmaltoSemip& prod) override;
    void visit(const TopBase& prod) override;
    void visit(const GelCostruttore& prod) override;
};

#endif // NAILSPRODUCTINFOVISITOR_H

