double calcularTempoEstacionado(string horaEntrada, string horaSaida)
{
    int horaEntradaHora, horaEntradaMinuto, horaSaidaHora, horaSaidaMinuto;
    sscanf(horaEntrada.c_str(), "%d:%d", &horaEntradaHora, &horaEntradaMinuto);
    sscanf(horaSaida.c_str(), "%d:%d", &horaSaidaHora, &horaSaidaMinuto);

    int minutosEntrada = horaEntradaHora * 60 + horaEntradaMinuto;
    int minutosSaida = horaSaidaHora * 60 + horaSaidaMinuto;

    int minutosEstacionado = minutosSaida - minutosEntrada;

    // Converter minutos para horas
    double horasEstacionado = static_cast<double>(minutosEstacionado) / 60.0;

    // Valor fixo de 8 reais por hora
    double valorPago = horasEstacionado * 8.0;

    return valorPago;
}

void inicializarVetor(Veiculo vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i].placa = "";
        vetor[i].horaEntrada = "";
    }
}

int entrarGaragem(Veiculo vetor[], int n, int quantidadeCarros)
{
    string placa, horaEntrada;
    bool carroLocalizado;

    cout << "Cadastro de veiculo\n";

    if (quantidadeCarros == n)
    {
        cout << "Garagem lotada\n";
    }
    else
    {
        while (true)
        {
            cout << "Informe a placa em Maiúsculo: ";
            cin >> placa;
            if (placa.length() == 7)
            {
                break;
            }
            else
            {
                cout << "Digite corretamente a placa\n";
            }
        }

        // Obter a hora de entrada atual
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[10];

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);
        horaEntrada = buffer;

        carroLocalizado = false;
        for (int i = 0; i < n; i++)
        {
            if (placa == vetor[i].placa)
            {
                cout << "Carro já na garagem\n";
                carroLocalizado = true;
                break;
            }
        }

        if (!carroLocalizado)
        {
            for (int i = 0; i < n; i++)
            {
                if (vetor[i].placa == "")
                {
                    vetor[i].placa = placa;
                    vetor[i].horaEntrada = horaEntrada;
                    quantidadeCarros++;
                    break;
                }
            }
        }
    }
    return quantidadeCarros;
}


void listarGaragem(Veiculo vetor[], int n, int quantidadeCarros)
{
    cout << "Listagem de veiculo\n";
    if (quantidadeCarros == 0)
    {
        cout << "Garagem vazia\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (vetor[i].placa != "")
            {
                cout << "Placa: " << vetor[i].placa << endl;
                cout << "Hora de Entrada: " << vetor[i].horaEntrada << endl;
                if (!vetor[i].horaSaida.empty())
                {
                    cout << "Hora de Saída: " << vetor[i].horaSaida << endl;
                    cout << "Valor Pago: R$ " << vetor[i].valorPago << endl;
                }
                cout << "-----------------------" << endl;
            }
        }
    }
}


int sairGaragem(Veiculo vetor[], int n, int quantidadeCarros)
{
    string placa, horaSaida;
    bool carroLocalizado;
    
    cout << "Saída de veiculo\n";

    if (quantidadeCarros == 0)
    {
        cout << "Garagem Vazia\n";
    }
    else
    {
        double valorPago; 

        while (true)
        {
            cout << "Informe a placa em Maiúsculo: ";
            cin >> placa;
            if (placa.length() == 7)
            {
                break;
            }
            else
            {
                cout << "Digite corretamente a placa\n";
            }
        }

        // Obter a hora de saída atual
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[10];

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);
        horaSaida = buffer;

        carroLocalizado = false;
        for (int i = 0; i < n; i++)
        {
            if (placa == vetor[i].placa)
            {
                cout << "Carro sendo retirado da garagem\n";
                vetor[i].horaSaida = horaSaida;

                // Calcular o valor a ser pago
                double valorHora = 8.0; 
                double valorMinuto = valorHora / 60.0;
                double tempoEstacionado = calcularTempoEstacionado(vetor[i].horaEntrada, vetor[i].horaSaida);
                valorPago = valorMinuto * tempoEstacionado;

                cout << "Tempo estacionado: " << tempoEstacionado << " minutos" << endl;
                cout << "Valor a ser pago: R$ " << valorPago << endl;

                vetor[i].placa = "";
                vetor[i].horaEntrada = "";
                quantidadeCarros--;
                carroLocalizado = true;
                break;
            }
        }

        if (!carroLocalizado)
        {
            cout << "Carro com esta placa não localizado\n";
        }
    }
    return quantidadeCarros;
}



