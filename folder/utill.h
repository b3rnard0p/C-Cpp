void cadastrarMedicao(Medicao medicoes[], int& numMedicoes) {
    if (numMedicoes >= TAM) {
        cout << "Limite de medicoes atingido.\n";
        return;
    }

    Medicao novaMedicao;
    cout << "Informe a data: ";
    cin >> novaMedicao.Data;
    cout << "Informe a hora: ";
    cin >> novaMedicao.Hora;
    cout << "Informe o valor da medicao: ";
    cin >> novaMedicao.valorMedicao;

    if (novaMedicao.valorMedicao >= 10 && novaMedicao.valorMedicao <= 600) {
        medicoes[numMedicoes] = novaMedicao;
        numMedicoes++;
        cout << "Medicao cadastrada com sucesso.\n";
    } else {
        cout << "Valor de medicao invalido.\n";
    }
}

void listarMedicoes(const Medicao medicoes[], int numMedicoes) {
    if (numMedicoes == 0) {
        cout << "Nenhuma medicao cadastrada.\n";
        return;
    }

    cout << "Medicoes cadastradas:\n";
    for (int i = 0; i < numMedicoes; i++) {
        cout << "Data: " << medicoes[i].Data << " Hora: " << medicoes[i].Hora
             << " Valor: " << medicoes[i].valorMedicao << endl;
    }
}

void calcularMediaMediana(const Medicao medicoes[], int numMedicoes) {
    if (numMedicoes == 0) {
        cout << "Nenhuma medicao cadastrada.\n";
        return;
    }

    int valores[TAM];
    for (int i = 0; i < numMedicoes; i++) {
        valores[i] = medicoes[i].valorMedicao;
    }

    double media = 0;
    for (int i = 0; i < numMedicoes; i++) {
        media += valores[i];
    }
    media /= numMedicoes;

    sort(valores, valores + numMedicoes);
    double mediana;
    if (numMedicoes % 2 == 0) {
        mediana = (valores[numMedicoes / 2 - 1] + valores[numMedicoes / 2]) / 2.0;
    } else {
        mediana = valores[numMedicoes / 2];
    }

    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;
}