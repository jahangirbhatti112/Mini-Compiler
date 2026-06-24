#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

class ASTNode {
public:
    virtual ~ASTNode() {}
    virtual std::string printTree(int indent) = 0; 
};

class NumberNode : public ASTNode {
public:
    std::string value;
    NumberNode(std::string val) : value(val) {}
    
    std::string printTree(int indent) override {
        return std::string(indent, ' ') + "|-- NumberNode: " + value + "\n";
    }
};

class BinaryOpNode : public ASTNode {
public:
    ASTNode* left;
    std::string op;
    ASTNode* right;

    BinaryOpNode(ASTNode* l, std::string o, ASTNode* r) : left(l), op(o), right(r) {}
    ~BinaryOpNode() {
        delete left;
        delete right;
    }
    
    std::string printTree(int indent) override {
        std::string res = std::string(indent, ' ') + "|-- BinaryOpNode (" + op + ")\n";
        if (left) res += left->printTree(indent + 4);
        if (right) res += right->printTree(indent + 4);
        return res;
    }
};

class AssignmentNode : public ASTNode {
public:
    std::string varName;
    ASTNode* valueNode;

    AssignmentNode(std::string name, ASTNode* valNode) : varName(name), valueNode(valNode) {}
    ~AssignmentNode() { delete valueNode; }
    
    std::string printTree(int indent) override {
        std::string res = std::string(indent, ' ') + "|-- AssignmentNode (=)\n";
        res += std::string(indent + 4, ' ') + "|-- Variable: " + varName + "\n";
        if (valueNode) res += valueNode->printTree(indent + 4);
        return res;
    }
};

class WhileNode : public ASTNode {
public:
    std::string conditionVar;
    ASTNode* body;

    WhileNode(std::string cond, ASTNode* loopBody) : conditionVar(cond), body(loopBody) {}
    ~WhileNode() { delete body; }
    
    std::string printTree(int indent) override {
        std::string res = std::string(indent, ' ') + "|-- WhileNode (loop)\n";
        res += std::string(indent + 4, ' ') + "|-- Condition Var: " + conditionVar + "\n";
        if (body) res += body->printTree(indent + 4);
        return res;
    }
};

class BlockNode : public ASTNode {
public:
    std::vector<ASTNode*> statements;

    ~BlockNode() {
        for (size_t i = 0; i < statements.size(); ++i) {
            delete statements[i];
        }
    }
    
    std::string printTree(int indent) override {
        std::string res = std::string(indent, ' ') + "|-- BlockNode {}\n";
        for (size_t i = 0; i < statements.size(); ++i) {
            res += statements[i]->printTree(indent + 4);
        }
        return res;
    }
};

#endif