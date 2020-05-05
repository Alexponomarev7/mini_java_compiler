#ifndef COMPILER_OBJECT_MAKE_EXPRESSION_H
#define COMPILER_OBJECT_MAKE_EXPRESSION_H

class ObjectMakeExpression : public Expression {
public:
    ObjectMakeExpression(TypeIdentifier typeIdentifier) :
        typeIdentifier_(std::move(typeIdentifier))
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    TypeIdentifier typeIdentifier_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_OBJECT_MAKE_EXPRESSION_H
