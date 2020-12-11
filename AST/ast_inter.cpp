#include "ast_inter.h"
#include <iostream>



#define HANDLE_CASE(n) \
    case NodeKind::n : return visit(reinterpret_cast<const n*>(root))



return_type Interpreter::execute(const ASTNode * root){
    switch (root->getKind())
    {
        HANDLE_CASE(NumberExpr);
        HANDLE_CASE(VariableExpr);
        HANDLE_CASE(AddExpr);
        HANDLE_CASE(SubExpr);
        HANDLE_CASE(MultExpr);
        HANDLE_CASE(DivExpr);
        HANDLE_CASE(AndExpr);
        HANDLE_CASE(OrExpr);
        HANDLE_CASE(XorExpr);
        HANDLE_CASE(NotExpr);
        HANDLE_CASE(ModExpr);
        HANDLE_CASE(ShlExpr);
        HANDLE_CASE(ShrExpr);
        HANDLE_CASE(LessThanExpr);
        HANDLE_CASE(LessThanEqExpr);
        HANDLE_CASE(GreaterThanExpr);
        HANDLE_CASE(GreaterThanEqExpr);
        HANDLE_CASE(EqualExpr);
        HANDLE_CASE(DiffExpr);
        HANDLE_CASE(StringExpr);
        HANDLE_CASE(AssignStmt);
        HANDLE_CASE(PrintStmt);
        HANDLE_CASE(SeqStmt);
        HANDLE_CASE(WhileStmt);
        HANDLE_CASE(IfStmt);
    default:
        throw std::string("No kind Found");
    }
}

return_type Interpreter::visit(const NumberExpr * expr){
    return_type t;
    t.value = expr->value;
    return t;
}
return_type Interpreter::visit(const VariableExpr * expr){
    return_type t;
    expr->isLocal ? t.value = local_vars[expr->ident] : t.value = global_vars[expr->ident];
    return t;
}

return_type Interpreter::visit(const AddExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value + b.value;
    return res;
}
return_type Interpreter::visit(const SubExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value - b.value;
    return res;
}
return_type Interpreter::visit(const MultExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value * b.value;
    return res;
}
return_type Interpreter::visit(const DivExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = b.value == 0 ? throw std::string("Can't divide by 0"): a.value / b.value;
    return res;
}
return_type Interpreter::visit(const AndExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value & b.value;
    return res;
}
return_type Interpreter::visit(const OrExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value | b.value;
    return res;
}
return_type Interpreter::visit(const XorExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value ^ b.value;
    return res;
}
return_type Interpreter::visit(const NotExpr * expr){
    return_type a = execute(expr->child.get());
    a.value = ~a.value;
    return a;
}
return_type Interpreter::visit(const ModExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value % b.value;
    return res;
}
return_type Interpreter::visit(const ShlExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value << b.value;
    return res;
}
return_type Interpreter::visit(const ShrExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value >> b.value;
    return res;
}
return_type Interpreter::visit(const LessThanExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value < b.value;
    return res;
}
return_type Interpreter::visit(const LessThanEqExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value <= b.value;
    return res;
}
return_type Interpreter::visit(const GreaterThanExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value > b.value;
    return res;
}
return_type Interpreter::visit(const GreaterThanEqExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value >= b.value;
    return res;
}
return_type Interpreter::visit(const EqualExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value == b.value;
    return res;
}
return_type Interpreter::visit(const DiffExpr * expr){
    return_type a = execute(expr->left.get());
    return_type b = execute(expr->right.get());

    return_type res;
    res.value = a.value != b.value;
    return res;
}

return_type Interpreter::visit(const StringExpr * expr){
    return_type a;
    a.str = expr->str;
    return a;
}
return_type Interpreter::visit(const AssignStmt * expr){
    return_type a = execute(expr->expr.get());
    global_vars[expr->ident] = a.value;
    return_type zero;
    return zero;
}
return_type Interpreter::visit(const PrintStmt * expr){
    return_type a = execute(expr->out.get());
    
    if(a.str.empty()){
        expr->breakLine ? std::cout<<a.value<<std::endl : std::cout<<a.value;
    }else{
        expr->breakLine ? std::cout<<a.str<<std::endl : std::cout<<a.str;
    }

    return_type zero;
    return zero;
}

return_type Interpreter::visit(const IfStmt * expr){
    return_type a = execute(expr->stmt_1.get());
    if(a.value)
        return execute(expr->stmt_1.get());
    else if( expr->stmt_2 != nullptr)
        return execute(expr->stmt_2.get());
    
    return_type zero;
    return zero;
}
return_type Interpreter::visit(const WhileStmt * expr){
    return_type a = execute(expr->cond.get());
    while(a.value){
        execute(expr->block.get());
        a = execute(expr->cond.get());
    }

    return_type zero;
    return zero;
}
return_type Interpreter::visit(const SeqStmt * expr){
    for(const auto& s : expr->sequence){
        execute(s.get());
    }
    return_type zero;
    return zero;
}