#ifndef GAME_V_1_MODELEXCEPTION_H
#define GAME_V_1_MODELEXCEPTION_H

#include <exception>
#include <string>

class ModelException : public ::std::exception {
private:
    std::string m_error;
public:
    ModelException(const std::string &error) {
        m_error = error;
    }

    const char *what() const noexcept { return m_error.c_str(); }
};



#endif //GAME_V_1_MODELEXCEPTION_H
