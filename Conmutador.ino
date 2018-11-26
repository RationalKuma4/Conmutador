//Abonado 1
#define S11 22	// input
#define S12 24	// input
#define S13 26	// input
#define S14 28	// peticion
#define S15 30	// salida

//Abonado 2
#define S21 32
#define S22 34
#define S23 36
#define S24 38
#define S25 40

//Abonado 3
#define S31 42
#define S32 44
#define S33 46
#define S34 48
#define S35 50

//Abonado 4
#define S41 23
#define S42 25
#define S43 27
#define S44 29
#define S45 31

//Abonado 5
#define S51 33
#define S52 35
#define S53 37
#define S54 39
#define S55 41

//Abonado 6
#define S61 43
#define S62 45
#define S63 47
#define S64 49
#define S65 51

int s11, s12, s13, s14, s15;
int s21, s22, s23, s24, s25;
int s31, s32, s33, s34, s35;
int s41, s42, s43, s44, s45;
int s51, s52, s53, s54, s55;
int s61, s62, s63, s64, s65;

struct Abonado
{
	int numeroSalida;
	String numero;
};

// Prototipos
void SetPinsMode();
void ReadPins();
void CreaAbonados();
void Ringtone(int pinSalida);
Abonado BucarAbonado(String numeroMarcado);
void Conmutar(Abonado abonadoDestino);

struct Abonado abonadoUno, abonadoDos, abonadoTres, abonadoCuatro,
	abonadoCinco, abonadoSeis;

String numMarc1, numMarc2, numMarc3, numMarc4, numMarc5,
numMarc6;

Abonado abonados[6];

void setup()
{
	SetPinsMode();
	Serial.begin(9600);
	Serial.println("Serial port open");
}

void loop()
{
	delay(1000);
	ReadPins();
	CreaAbonados();

	// Vemos estados
	if (s14 == 1)
	{
		numMarc1 = String(s11) + String(s12) + String(s13);
		auto encontrado = BucarAbonado(numMarc1);
		Conmutar(encontrado);
	}

	if (s24 == 1)
	{
		numMarc2 = String(s21) + String(s22) + String(s23);
		auto encontrado = BucarAbonado(numMarc2);
		Conmutar(encontrado);
	}

	if (s34 == 1)
	{
		numMarc3 = String(s31) + String(s32) + String(s33);
		auto encontrado = BucarAbonado(numMarc3);
		Conmutar(encontrado);
	}

	if (s44 == 1)
	{
		numMarc4 = String(s41) + String(s42) + String(s43);
		auto encontrado = BucarAbonado(numMarc4);
		Conmutar(encontrado);
	}

	if (s54 == 1)
	{
		numMarc5 = String(s51) + String(s52) + String(s53);
		auto encontrado = BucarAbonado(numMarc5);
		Conmutar(encontrado);
	}

	if (s64 == 1)
	{
		numMarc6 = String(s61) + String(s62) + String(s63);
		auto encontrado = BucarAbonado(numMarc6);
		Conmutar(encontrado);
	}
}

void SetPinsMode()
{
	pinMode(S11, INPUT);
	pinMode(S12, INPUT);
	pinMode(S13, INPUT);
	pinMode(S14, INPUT);
	pinMode(S15, OUTPUT);

	pinMode(S21, INPUT);
	pinMode(S22, INPUT);
	pinMode(S23, INPUT);
	pinMode(S24, INPUT);
	pinMode(S25, OUTPUT);

	pinMode(S31, INPUT);
	pinMode(S32, INPUT);
	pinMode(S33, INPUT);
	pinMode(S34, INPUT);
	pinMode(S35, OUTPUT);

	pinMode(S41, INPUT);
	pinMode(S42, INPUT);
	pinMode(S43, INPUT);
	pinMode(S44, INPUT);
	pinMode(S55, OUTPUT);

	pinMode(S51, INPUT);
	pinMode(S52, INPUT);
	pinMode(S53, INPUT);
	pinMode(S54, INPUT);
	pinMode(S55, OUTPUT);

	pinMode(S61, INPUT);
	pinMode(S62, INPUT);
	pinMode(S63, INPUT);
	pinMode(S64, INPUT);
	pinMode(S65, OUTPUT);
}

void ReadPins()
{
	s11 = digitalRead(S11);
	s12 = digitalRead(S12);
	s13 = digitalRead(S13);
	s14 = digitalRead(S14);

	s21 = digitalRead(S21);
	s22 = digitalRead(S22);
	s23 = digitalRead(S23);
	s24 = digitalRead(S24);

	s31 = digitalRead(S31);
	s32 = digitalRead(S32);
	s33 = digitalRead(S33);
	s34 = digitalRead(S34);

	s41 = digitalRead(S41);
	s42 = digitalRead(S42);
	s43 = digitalRead(S43);
	s44 = digitalRead(S44);

	s51 = digitalRead(S51);
	s52 = digitalRead(S52);
	s53 = digitalRead(S53);
	s54 = digitalRead(S54);

	s61 = digitalRead(S61);
	s62 = digitalRead(S62);
	s63 = digitalRead(S63);
	s64 = digitalRead(S64);
}

void CreaAbonados()
{
	abonadoUno.numeroSalida = S15;
	abonadoUno.numero = "001";

	abonadoDos.numeroSalida = S25;
	abonadoDos.numero = "010";

	abonadoTres.numeroSalida = S35;
	abonadoTres.numero = "011";

	abonadoCuatro.numeroSalida = S45;
	abonadoCuatro.numero = "100";

	abonadoCinco.numeroSalida = S55;
	abonadoCinco.numero = "101";

	abonadoSeis.numeroSalida = S65;
	abonadoSeis.numero = "110";

	abonados[0] = abonadoUno;
	abonados[1] = abonadoDos;
	abonados[2] = abonadoTres;
	abonados[3] = abonadoCuatro;
	abonados[4] = abonadoCinco;
	abonados[5] = abonadoSeis;
}

void Ringtone(int pinSalida)
{
	for (int i = 0; i < 1000; ++i)
	{
		digitalWrite(pinSalida, HIGH);
		delayMicroseconds(500);
		digitalWrite(pinSalida, LOW);
		delayMicroseconds(500);
	}
}

Abonado BucarAbonado(String numeroMarcado)
{
	struct Abonado abonado;
	abonado.numero = "N";
	abonado.numeroSalida = 0;

	for (int i = 0; i < 6; ++i)
	{
		if (numeroMarcado.equals(abonados[i].numero))
		{
			abonado = abonados[i];
		}
	}
	return abonado;
}

void Conmutar(Abonado abonadoDestino)
{
	if (!abonadoDestino.numero.equals("N"))
	{
		Ringtone(abonadoDestino.numeroSalida);
	}
}


