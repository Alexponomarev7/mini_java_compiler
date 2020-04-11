#ifndef COMPILER_SYMBOL_TREE_VISITOR_H
#define COMPILER_SYMBOL_TREE_VISITOR_H

#include "template_visitor.h"
#include "symbol_table/table.h"
#include "symbol_table/scope_layer_tree.h"


class SymbolTreeVisitor : public TemplateVisitor<Type> {
public:
    explicit SymbolTreeVisitor();

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

    ScopeLayer* GetRoot();

private:
    ScopeLayerTree tree_;
    ScopeLayer* current_layer_;

    struct CreateScopeLayer {
        explicit CreateScopeLayer(SymbolTreeVisitor* symbolTreeVisitor) : symbolTreeVisitor_(symbolTreeVisitor) {
            symbolTreeVisitor_->current_layer_ = new ScopeLayer(symbolTreeVisitor_->current_layer_);
        }

        ~CreateScopeLayer() {
            symbolTreeVisitor_->current_layer_ = symbolTreeVisitor_->current_layer_->GetParent();
        }

        SymbolTreeVisitor* symbolTreeVisitor_;
    };
};


#endif //COMPILER_SYMBOL_TREE_VISITOR_H
