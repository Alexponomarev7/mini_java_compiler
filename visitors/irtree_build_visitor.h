#ifndef COMPILER_IRTREE_BUILD_VISITOR_H
#define COMPILER_IRTREE_BUILD_VISITOR_H

#include <unordered_map>
#include "template_visitor.h"
#include "symbol_table/table.h"
#include "symbol_table/scope_layer_tree.h"
#include "function-mechanisms/function_table.h"
#include "function-mechanisms/function_storage.h"
#include "function-mechanisms/frame_translator.h"

#include <irtree/tree_wrapper/expression_wrapper.h>
#include <irtree/nodes/expressions/const_expression.h>
#include <irtree/tree_wrapper/conditional_wrappers/negate_conditional_wrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/and_conditional_wrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/or_conditional_wrapper.h>
#include <irtree/types/binary_operator_type.h>
#include <irtree/generators/temporary.h>
#include <irtree/nodes/expressions/binop_expression.h>
#include <irtree/nodes/expressions/temp_expression.h>
#include <irtree/nodes/expressions/mem_expression.h>
#include <irtree/nodes/statements/move_statement.h>
#include <irtree/tree_wrapper/statement_wrapper.h>
#include <irtree/nodes/statements/label_statement.h>
#include <irtree/nodes/statements/seq_statement.h>
#include <irtree/nodes/statements/jump_statement.h>
#include <irtree/nodes/expression_list.h>
#include <irtree/nodes/expressions/call_expression.h>
#include <irtree/nodes/expressions/name_expression.h>
#include <irtree/types/logic_operator_type.h>
#include <irtree/tree_wrapper/conditional_wrappers/relative_conditional_wrapper.h>

#include <irtree/tree_wrapper/statement_wrapper.h>

using IrtMapping = std::unordered_map<std::string, IRT::Statement*>;

class IrtreeBuildVisitor : public TemplateVisitor<IRT::SubtreeWrapper*> {
public:
    explicit IrtreeBuildVisitor(ScopeLayerTree* layer_tree);

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

    IrtMapping GetTrees();

private:
    std::unordered_map<std::string, IRT::FrameTranslator*> frame_translator_;

    IRT::FrameTranslator *current_frame_;
    ScopeLayerTree* tree_;

    IrtMapping method_trees_;
};

#endif //COMPILER_IRTREE_BUILD_VISITOR_H
