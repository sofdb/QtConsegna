#ifndef NAILSPRODUCTVISITOR_H
#define NAILSPRODUCTVISITOR_H

class SmaltoSemip;
class TopBase;
class GelCostruttore;

class NailsProductVisitor
{
public:
    virtual ~NailsProductVisitor() = default;
    virtual void visit(const SmaltoSemip& prod) = 0;
    virtual void visit(const TopBase& prod) = 0;
    virtual void visit(const GelCostruttore& prod) = 0;
};

#endif // NAILSPRODUCTVISITOR_H

