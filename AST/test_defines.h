#ifndef __AST_DEF__
#define __AST_DEF__

// Defines to test the AST

#define VAR(a,b) std::make_shared<VariableExpr>(a,b)
#define NUMBER(a) std::make_shared<NumberExpr>(a)

#define ADD(a,b) std::make_shared<AddExpr>(a,b)
#define SUB(a,b) std::make_shared<SubExpr>(a,b)
#define MULT(a,b) std::make_shared<MultExpr>(a,b)
#define DIV(a,b) std::make_shared<DivExpr>(a,b)
#define AND(a,b) std::make_shared<AndExpr>(a,b)
#define OR(a,b) std::make_shared<OrExpr>(a,b)
#define XOR(a,b) std::make_shared<XorExpr>(a,b)
#define NOT(a) std::make_shared<NotExpr>(a)
#define MOD(a,b) std::make_shared<ModExpr>(a,b)
#define SHL(a,b) std::make_shared<ShlExpr>(a,b)
#define SHR(a,b) std::make_shared<ShrExpr>(a,b)
#define LESSTHAN(a,b) std::make_shared<LessThanExpr>(a,b)
#define LESSTHANEQ(a,b) std::make_shared<LessThanEqExpr>(a,b)
#define GREATERTHAN(a,b) std::make_shared<GreaterThanExpr>(a,b)
#define GREATERTHANEQ(a,b) std::make_shared<GreaterThanEqExpr>(a,b)
#define EQUAL(a,b) std::make_shared<EqualExpr>(a,b)
#define DIFF(a,b) std::make_shared<DiffExpr>(a,b)

#endif