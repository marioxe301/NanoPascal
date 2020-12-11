#ifndef __KINDS__
#define __KINDS__

enum class NodeKind{
    NumberExpr,
    VariableExpr,
    AddExpr,
    SubExpr,
    MultExpr,
    DivExpr,
    AndExpr,
    OrExpr,
    XorExpr,
    NotExpr,
    ModExpr,
    ShlExpr,
    ShrExpr,
    LessThanExpr,
    LessThanEqExpr,
    GreaterThanExpr,
    GreaterThanEqExpr,
    EqualExpr,
    DiffExpr
};

#endif