//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#ifndef COMPILER_FUNCTION_CALL_VISITOR_H
#define COMPILER_FUNCTION_CALL_VISITOR_H

#include "template_visitor.h"
#include "visitors/symbol_tree_visitor.h"
#include "symbol_table/scope_layer.h"
#include <stack>
#include "function-mechanisms/frame.h"
#include "function-mechanisms/function_table.h"
#include "symbol_table/scope_layer_tree.h"
#include "components/program.h"

#include <map>
#include <exception>
#include <iostream>
#include <vector>
#include <cassert>

#include "types/types.h"

class FunctionCallVisitor : public TemplateVisitor<std::shared_ptr<Object>> {
public:
    FunctionCallVisitor(ScopeLayer* function_scope, std::shared_ptr<ClassMethodType> function, ScopeLayerTree* tree);

    void SetTree(ScopeLayerTree* tree);
    void SetParams(const std::vector<std::shared_ptr<Object>>& params);

    void Visit(Program* program) override;

    void Visit(MainClass* mainClass) override;
    void Visit(Class* classObj) override;
    void Visit(Formal* formal) override;
    void Visit(MethodInvocation* methodInvocation) override;

    void Visit(VariableDeclaration* variableDeclaration) override;
    void Visit(MethodDeclaration* methodDeclaration) override;

    void Visit(ArrayMakeExpression* expression) override;
    void Visit(BinaryExpression* expression) override;
    void Visit(InverseExpression* expression) override;
    void Visit(MethodInvocationExpression* expression) override;
    void Visit(ObjectMakeExpression* expression) override;
    void Visit(SimpleExpression* expression) override;
    void Visit(LengthExpression* expression) override;
    void Visit(NumberExpression* expression) override;

    void Visit(AssertStatement* statement) override;
    void Visit(IfElseStatement* statement) override;
    void Visit(IfStatement* statement) override;
    void Visit(LocalVariableDeclarationStatement* statement) override;
    void Visit(MethodInvocationStatement* statement) override;
    void Visit(PrintlnStatement* statement) override;
    void Visit(ReturnStatement* statement) override;
    void Visit(ScopeStatements* statement) override;
    void Visit(SetLvalueStatement* statement) override;
    void Visit(WhileStatement* statement) override;

    Frame& GetFrame();

    void SkipScope();

private:
    ScopeLayer* root_layer;
    ScopeLayer* current_layer_;
    std::stack<int> offsets_;

    Frame frame;
    FunctionTable table_;
    ScopeLayerTree* tree_;
    bool returned_ = false;
};


#endif //COMPILER_FUNCTION_CALL_VISITOR_H
