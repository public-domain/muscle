#include "myutils.h"
#include "params.h"
#include "mx.h"
#include <math.h>

#define CharToLetter(c)		byte(c)

////////////////////////////////////////////
// From PROBCONS source
////////////////////////////////////////////
static float initDistrib2Default[] = { 0.6814756989f, 8.615339902e-05f, 8.615339902e-05f, 0.1591759622f, 0.1591759622f };
static float gapOpen2Default[] = { 0.0119511066f, 0.0119511066f, 0.008008334786f, 0.008008334786f };
static float gapExtend2Default[] = { 0.3965826333f, 0.3965826333f, 0.8988758326f, 0.8988758326f };

static string alphabetDefault = "ARNDCQEGHILKMFPSTWYV";
static float emitSingleDefault[20] = {
  0.07831005f, 0.05246024f, 0.04433257f, 0.05130349f, 0.02189704f,
  0.03585766f, 0.05615771f, 0.07783433f, 0.02601093f, 0.06511648f,
  0.09716489f, 0.05877077f, 0.02438117f, 0.04463228f, 0.03940142f,
  0.05849916f, 0.05115306f, 0.01203523f, 0.03124726f, 0.07343426f
};

static float emitPairsDefault[20][20] = {
  {0.02373072f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00244502f, 0.01775118f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00210228f, 0.00207782f, 0.01281864f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00223549f, 0.00161657f, 0.00353540f, 0.01911178f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00145515f, 0.00044701f, 0.00042479f, 0.00036798f, 0.01013470f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00219102f, 0.00253532f, 0.00158223f, 0.00176784f, 0.00032102f, 0.00756604f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00332218f, 0.00268865f, 0.00224738f, 0.00496800f, 0.00037956f, 0.00345128f, 0.01676565f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00597898f, 0.00194865f, 0.00288882f, 0.00235249f, 0.00071206f, 0.00142432f, 0.00214860f, 0.04062876f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00114353f, 0.00132105f, 0.00141205f, 0.00097077f, 0.00026421f, 0.00113901f, 0.00131767f, 0.00103704f, 0.00867996f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00318853f, 0.00138145f, 0.00104273f, 0.00105355f, 0.00094040f, 0.00100883f, 0.00124207f, 0.00142520f, 0.00059716f, 0.01778263f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00449576f, 0.00246811f, 0.00160275f, 0.00161966f, 0.00138494f, 0.00180553f, 0.00222063f, 0.00212853f, 0.00111754f, 0.01071834f, 0.03583921f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00331693f, 0.00595650f, 0.00257310f, 0.00252518f, 0.00046951f, 0.00312308f, 0.00428420f, 0.00259311f, 0.00121376f, 0.00157852f, 0.00259626f, 0.01612228f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00148878f, 0.00076734f, 0.00063401f, 0.00047808f, 0.00037421f, 0.00075546f, 0.00076105f, 0.00066504f, 0.00042237f, 0.00224097f, 0.00461939f, 0.00096120f, 0.00409522f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00165004f, 0.00090768f, 0.00084658f, 0.00069041f, 0.00052274f, 0.00059248f, 0.00078814f, 0.00115204f, 0.00072545f, 0.00279948f, 0.00533369f, 0.00087222f, 0.00116111f, 0.01661038f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00230618f, 0.00106268f, 0.00100282f, 0.00125381f, 0.00034766f, 0.00090111f, 0.00151550f, 0.00155601f, 0.00049078f, 0.00103767f, 0.00157310f, 0.00154836f, 0.00046718f, 0.00060701f, 0.01846071f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00631752f, 0.00224540f, 0.00301397f, 0.00285226f, 0.00094867f, 0.00191155f, 0.00293898f, 0.00381962f, 0.00116422f, 0.00173565f, 0.00250962f, 0.00312633f, 0.00087787f, 0.00119036f, 0.00180037f, 0.01346609f, 0.0f, 0.0f, 0.0f, 0.0f},
  {0.00389995f, 0.00186053f, 0.00220144f, 0.00180488f, 0.00073798f, 0.00154526f, 0.00216760f, 0.00214841f, 0.00077747f, 0.00248968f, 0.00302273f, 0.00250862f, 0.00093371f, 0.00107595f, 0.00147982f, 0.00487295f, 0.01299436f, 0.0f, 0.0f, 0.0f},
  {0.00039119f, 0.00029139f, 0.00021006f, 0.00016015f, 0.00010666f, 0.00020592f, 0.00023815f, 0.00038786f, 0.00019097f, 0.00039549f, 0.00076736f, 0.00028448f, 0.00016253f, 0.00085751f, 0.00015674f, 0.00026525f, 0.00024961f, 0.00563625f, 0.0f, 0.0f},
  {0.00131840f, 0.00099430f, 0.00074960f, 0.00066005f, 0.00036626f, 0.00070192f, 0.00092548f, 0.00089301f, 0.00131038f, 0.00127857f, 0.00219713f, 0.00100817f, 0.00054105f, 0.00368739f, 0.00047608f, 0.00102648f, 0.00094759f, 0.00069226f, 0.00999315f, 0.0f},
  {0.00533241f, 0.00169359f, 0.00136609f, 0.00127915f, 0.00119152f, 0.00132844f, 0.00178697f, 0.00194579f, 0.00071553f, 0.01117956f, 0.00914460f, 0.00210897f, 0.00197461f, 0.00256159f, 0.00135781f, 0.00241601f, 0.00343452f, 0.00038538f, 0.00148001f, 0.02075171f}
};
////////////////////////////////////////////
// End from PROBCONS source
////////////////////////////////////////////

const unsigned PCMX_M = 0;
const unsigned PCMX_D = 1;
const unsigned PCMX_I = 2;
const unsigned PCMX_X = 3;
const unsigned PCMX_Y = 4;

float *g_PCEmit;

void SetPCTransScores()
	{
	TransSM = log(initDistrib2Default[PCMX_M]);
	TransSD = log(initDistrib2Default[PCMX_D]);
	TransSI = TransSD;
	TransSX = log(initDistrib2Default[PCMX_X]);
	TransSY = TransSX;

	TransME = TransSM;
	TransDE = TransSD;
	TransIE = TransSI;
	TransXE = TransSX;
	TransYE = TransSY;

	TransMM = log(1.0f - 2*gapOpen2Default[0] - 2*gapOpen2Default[2]);
	TransDM = log(1.0f - gapExtend2Default[0]);
	TransIM = TransDM;
	TransXM = log(1.0f - gapExtend2Default[2]);
	TransYM = TransXM;

	TransMD = log(gapOpen2Default[0]);
	TransMI = TransMD;

	TransDD = log(gapExtend2Default[0]);
	TransII = TransDD;

	TransDM = log(1.0f - gapExtend2Default[0]);
	TransIM = TransDM;

	TransMX = log(gapOpen2Default[2]);
	TransMY = TransMX;

	TransXX = log(gapExtend2Default[2]);
	TransYY = TransXX;

	TransXM = log(1.0f - gapExtend2Default[2]);
	TransYM = TransXM;

	TransMM = log(1.0f - 2*gapOpen2Default[0] - 2*gapOpen2Default[2]);
	}

void SetPCHMMSubstMx()
	{
	Mx<float> &SubstMxf = GetSubstMxf();
	if (SubstMxf.m_Name == "PCHMMSubstMx")
		return;
	SubstMxf.Alloc("PCHMMSubstMx", 256, 256);
	SubstMxf.Init(0);
	SubstMxf.SetAlpha(alphabetDefault);

	float **Mx = SubstMxf.GetData();

	const unsigned N = SIZE(alphabetDefault);
	for (unsigned i = 0; i < N; ++i)
		{
		byte ai = alphabetDefault[i];
		unsigned Letteri = CharToLetter(ai);

		for (unsigned j = 0; j <= i; ++j)
			{
			byte aj = alphabetDefault[j];
			unsigned Letterj = CharToLetter(aj);

			float v = log(emitPairsDefault[i][j]);

			Mx[Letteri][Letterj] = v;
			Mx[Letterj][Letteri] = v;
			}
		}

	float ScoreA = 0;
	for (unsigned i = 0; i < 20; ++i)
		{
		unsigned LetterA = CharToLetter('A');
		unsigned Letter = CharToLetter(alphabetDefault[i]);
		ScoreA += Mx[Letter][LetterA];
		}
	ScoreA /= 20;

	byte LetterX = CharToLetter('X');
	byte LetterB = CharToLetter('B');
	byte LetterZ = CharToLetter('Z');

	for (unsigned i = 0; i < 20; ++i)
		{
		unsigned Letteri = alphabetDefault[i];

		Mx[LetterX][Letteri] = ScoreA;
		Mx[Letteri][LetterX] = ScoreA;

		Mx[LetterB][Letteri] = ScoreA;
		Mx[Letteri][LetterB] = ScoreA;

		Mx[LetterZ][Letteri] = ScoreA;
		Mx[Letteri][LetterZ] = ScoreA;
		}

	Mx[LetterX][LetterX] = ScoreA;
	Mx[LetterX][LetterB] = ScoreA;
	Mx[LetterX][LetterZ] = ScoreA;

	Mx[LetterB][LetterX] = ScoreA;
	Mx[LetterB][LetterB] = ScoreA;
	Mx[LetterB][LetterZ] = ScoreA;

	Mx[LetterZ][LetterX] = ScoreA;
	Mx[LetterZ][LetterB] = ScoreA;
	Mx[LetterZ][LetterZ] = ScoreA;
	}

static void SetPCEmit()
	{
	g_PCEmit = new float[256];
	for (unsigned i = 0; i < 256; ++i)
		g_PCEmit[i] = -3.0f;

	const unsigned N = SIZE(alphabetDefault);
	for (unsigned i = 0; i < N; ++i)
		{
		byte ai = alphabetDefault[i];
		float x = log(emitSingleDefault[i]);

		unsigned Letter = CharToLetter(ai);
		g_PCEmit[Letter] = x;
		}
	}

void SetModelProbconsHMM()
	{
	SetPCEmit();
	SetPCHMMSubstMx();
	SetPCTransScores();
	}