enum TipoFuncionario {
    PROFESSOR,
    COORDENADOR
};

struct Funcionario {
    string nome;
    int numero;
    TipoFuncionario tipo;
};

struct PermissaoAluno {
    int numero;
    bool permissao;
};

struct Aluno {
    string nome;
    int numero;
};

struct SalaAula {
    string nome;
    string predio;
};