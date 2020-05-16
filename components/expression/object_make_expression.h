#ifndef COMPILER_OBJECT_MAKE_EXPRESSION_H
#define COMPILER_OBJECT_MAKE_EXPRESSION_H

class ObjectMakeExpression : public Expression {
public:
    ObjectMakeExpression(TypeIdentifier typeIdentifier) :
        typeIdentifier_(std::move(typeIdentifier))
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    TypeIdentifier typeIdentifier_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_OBJECT_MAKE_EXPRESSION_H
