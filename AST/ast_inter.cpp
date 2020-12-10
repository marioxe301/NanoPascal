#include "ast_inter.h"

#define HANDLE_CASE(n) \
    case NodeKind::n : return visit(reinterpret_cast<const n*>(root))