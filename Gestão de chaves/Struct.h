// Enum para representar o tipo de funcionário
enum TipoFuncionario {
    PROFESSOR,
    COORDENADOR
};

// Struct para representar um funcionário
struct Funcionario {
    string nome;
    int numero;
    TipoFuncionario tipo;
};

// Struct para representar um aluno
struct Aluno {
    string nome;
    int numero;
};

// Struct para representar uma sala de aula
struct SalaAula {
    string nome;
    string predio;
     bool chavePega;  // Adiciona um indicador se a chave foi pega
};