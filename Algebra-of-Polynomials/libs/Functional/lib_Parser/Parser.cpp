#include "Parser.h"

Parser::Parser() {
    targetExpression = "";
}

Parser::Parser(std::string expression) {
    targetExpression = expression;
    removeSpaces();
}

List<Monom> Parser::parse() {
     std::string delimeter = "+-";
     std::string token;
     size_t start = 0, end = targetExpression.find_first_of(delimeter, start);
     if (end != 0) {
         token = targetExpression.substr(start, end - start);
         parseMonom(token);
         start = ++end;
         while ((end = targetExpression.find_first_of(delimeter,start)) != std::string::npos) {
             token = targetExpression.substr(start - 1, end - start + 1);
             parseMonom(token);
             start = ++end;
         }
         parseMonom(targetExpression.substr(start - 1));
     } else if (targetExpression.find_first_of(delimeter,start + 1) != std::string::npos) {
         end = targetExpression.find_first_of(delimeter, start + 1);
         token = targetExpression.substr(start, end - start);
         parseMonom(token);
         start = ++end;
         while((end = targetExpression.find_first_of(delimeter, start)) != std::string::npos) {
             token = targetExpression.substr(start - 1, end - start + 1);
             parseMonom(token);
             start = ++end;
         }
         parseMonom(token);
     } else {
         parseMonom(targetExpression);
     }
     return list;
}


//CHECK
void Parser::removeSpaces() {
    targetExpression.erase(std::remove(targetExpression.begin(), targetExpression.end(), ' '), targetExpression.end());
}
//REWORK
void Parser::parseMonom(std::string monom) {
    double coeff = 1;
    int numVars = 3;
    int powers[] = { 0, 0, 0};
    std::string varsName = "xyz";
    for (int i = 0; i < monom.size(); i++) {
        if (monom[i] >= '0' && monom[i] <= '9') {
            coeff = std::stod(monom);
        }
        if (monom[i] == 'x' || monom[i] == 'y' || monom[i] == 'z') {
            for (int j = 0; j < 3; j++) {
                if (monom[i] == varsName[j]) {
                    if (monom[i + 1] == '^') {
                        powers[j] = std::stoi(monom.substr(i + 2));
                    }
                    else {
                        powers[j] = 1;
                    }
                }
            }
        }
    }
    Monom temp(coeff, numVars, powers);
    int index = list.contains(temp);
    if (index != -1) {
        if ((list.get(index).getCoeff() > 0 && temp.getCoeff() < 0) || (list.get(index).getCoeff() < 0 && temp.getCoeff() > 0)) {
            list.remove(list.get(index));
        } else {
          list.get(index) += temp;
        }
    } else {
        list.push_back(temp);
    }
}

void Parser::removeSpaces(std::string& expression) {
    std::string delimeter = " ";
    size_t start = 0, end = expression.find_first_of(delimeter, start);
    std::string token;
    while (expression.find_first_of(delimeter, start)) {
        token.append(expression.substr(start, end - start));
        start = ++end;
    }
    expression = token;
}
