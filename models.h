// dualg8pcmx2:
// --model localaff+global --matrix PCCRFMX
// --G 5.0 --E 0.23
// --g 5.3712 --e 1.622 --tg 2.0132 --te 0.8336 --dg 7.1494 --de 0.2215 --tdg 7.9865 --tde 0.074

C(SWCRF)
C(Full)

// Algo, Param
A(SWCRF, MD)
A(SWCRF, MI)
A(SWCRF, DD)
A(SWCRF, II)

A(PCCRF, DD)
A(PCCRF, DE)
A(PCCRF, IE)
A(PCCRF, II)
A(PCCRF, MD)
A(PCCRF, ME)
A(PCCRF, MI)
A(PCCRF, MX)
A(PCCRF, MY)
A(PCCRF, SD)
A(PCCRF, SI)
A(PCCRF, SX)
A(PCCRF, SY)
A(PCCRF, XE)
A(PCCRF, XX)
A(PCCRF, YE)
A(PCCRF, YY)

A(PCHMM, DD)
A(PCHMM, DE)
A(PCHMM, DM)
A(PCHMM, IE)
A(PCHMM, II)
A(PCHMM, IM)
A(PCHMM, MD)
A(PCHMM, ME)
A(PCHMM, MI)
A(PCHMM, MM)
A(PCHMM, MX)
A(PCHMM, MY)
A(PCHMM, SD)
A(PCHMM, SI)
A(PCHMM, SM)
A(PCHMM, SX)
A(PCHMM, SY)
A(PCHMM, XE)
A(PCHMM, XM)
A(PCHMM, XX)
A(PCHMM, YE)
A(PCHMM, YM)
A(PCHMM, YY)

A(Full, SD)
A(Full, SI)
A(Full, SX)
A(Full, SY)
A(Full, MD)
A(Full, MI)
A(Full, MX)
A(Full, MY)
A(Full, DD)
A(Full, II)
A(Full, XX)
A(Full, YY)
A(Full, LDD)
A(Full, LII)
A(Full, LXX)
A(Full, LYY)
A(Full, RDD)
A(Full, RII)
A(Full, RMD)
A(Full, RMI)
A(Full, RMX)
A(Full, RMY)
A(Full, RXX)
A(Full, RYY)

//	Model				Algorithm
M(	localaff,			SWCRF)
M(	localaffnuc,		SWCRF)
M(	globalaff,			Full)
M(	globalaffnuc,		Full)
M(	globaltermaff,		Full)
M(	globaldaff,			Full)
M(	global,				Full)
M(	globalnuc,			Full)

P(	localaff,			G,		MD)
P(	localaff,			G,		MI)
P(	localaff,			E,		DD)
P(	localaff,			E,		II)

P(	localaffnuc,		G,		MD)
P(	localaffnuc,		G,		MI)
P(	localaffnuc,		E,		DD)
P(	localaffnuc,		E,		II)

P(	localaffnuc,		G,		MD)
P(	localaffnuc,		G,		MI)
P(	localaffnuc,		E,		DD)
P(	localaffnuc,		E,		II)

P(	globalaff,			g,		SD)
P(	globalaff,			g,		SI)
P(	globalaff,			g,		MD)
P(	globalaff,			g,		MI)
P(	globalaff,			e,		DD)
P(	globalaff,			e,		II)
P(	globalaff,			e,		LDD)
P(	globalaff,			e,		LII)
P(	globalaff,			g,		RMD)
P(	globalaff,			g,		RMI)
P(	globalaff,			e,		RDD)
P(	globalaff,			e,		RII)

P(	globalaffnuc,			g,		SD)
P(	globalaffnuc,			g,		SI)
P(	globalaffnuc,			g,		MD)
P(	globalaffnuc,			g,		MI)
P(	globalaffnuc,			e,		DD)
P(	globalaffnuc,			e,		II)
P(	globalaffnuc,			e,		LDD)
P(	globalaffnuc,			e,		LII)
P(	globalaffnuc,			g,		RMD)
P(	globalaffnuc,			g,		RMI)
P(	globalaffnuc,			e,		RDD)
P(	globalaffnuc,			e,		RII)

P(	globaltermaff,		tg,		SD)
P(	globaltermaff,		tg,		SI)
P(	globaltermaff,		g,		MD)
P(	globaltermaff,		g,		MI)
P(	globaltermaff,		e,		DD)
P(	globaltermaff,		e,		II)
P(	globaltermaff,		te,		LDD)
P(	globaltermaff,		te,		LII)
P(	globaltermaff,		tg,		RMD)
P(	globaltermaff,		tg,		RMI)
P(	globaltermaff,		te,		RDD)
P(	globaltermaff,		te,		RII)

P(	globaldaff,			g,		SD)
P(	globaldaff,			g,		SI)
P(	globaldaff,			g,		MD)
P(	globaldaff,			g,		MI)
P(	globaldaff,			dg,		SX)
P(	globaldaff,			dg,		SY)
P(	globaldaff,			dg,		MX)
P(	globaldaff,			dg,		MY)
P(	globaldaff,			g,		RMD)
P(	globaldaff,			g,		RMI)
P(	globaldaff,			dg,		RMX)
P(	globaldaff,			dg,		RMY)
P(	globaldaff,			e,		DD)
P(	globaldaff,			e,		LDD)
P(	globaldaff,			e,		RDD)
P(	globaldaff,			e,		II)
P(	globaldaff,			e,		LII)
P(	globaldaff,			e,		RII)
P(	globaldaff,			de,		XX)
P(	globaldaff,			de,		LXX)
P(	globaldaff,			de,		RXX)
P(	globaldaff,			de,		YY)
P(	globaldaff,			de,		LYY)
P(	globaldaff,			de,		RYY)

P(	global,				tg,		SD)
P(	global,				tg,		SI)
P(	global,				tdg,	SX)
P(	global,				tdg,	SY)
P(	global,				g,		MD)
P(	global,				g,		MI)
P(	global,				dg,		MX)
P(	global,				dg,		MY)
P(	global,				tg,		RMD)
P(	global,				tg,		RMI)
P(	global,				tdg,	RMX)
P(	global,				tdg,	RMY)
P(	global,				e,		DD)
P(	global,				te,		LDD)
P(	global,				te,		RDD)
P(	global,				e,		II)
P(	global,				te,		LII)
P(	global,				te,		RII)
P(	global,				de,		XX)
P(	global,				tde,	LXX)
P(	global,				tde,	RXX)
P(	global,				de,		YY)
P(	global,				tde,	LYY)
P(	global,				tde,	RYY)

P(	globalnuc,				tg,		SD)
P(	globalnuc,				tg,		SI)
P(	globalnuc,				tdg,	SX)
P(	globalnuc,				tdg,	SY)
P(	globalnuc,				g,		MD)
P(	globalnuc,				g,		MI)
P(	globalnuc,				dg,		MX)
P(	globalnuc,				dg,		MY)
P(	globalnuc,				tg,		RMD)
P(	globalnuc,				tg,		RMI)
P(	globalnuc,				tdg,	RMX)
P(	globalnuc,				tdg,	RMY)
P(	globalnuc,				e,		DD)
P(	globalnuc,				te,		LDD)
P(	globalnuc,				te,		RDD)
P(	globalnuc,				e,		II)
P(	globalnuc,				te,		LII)
P(	globalnuc,				te,		RII)
P(	globalnuc,				de,		XX)
P(	globalnuc,				tde,	LXX)
P(	globalnuc,				tde,	RXX)
P(	globalnuc,				de,		YY)
P(	globalnuc,				tde,	LYY)
P(	globalnuc,				tde,	RYY)

Q(G)
Q(E)
Q(g)
Q(e)
Q(dg)
Q(de)
Q(tg)
Q(te)
Q(tdg)
Q(tde)
Q(Lg)
Q(Le)
Q(Ldg)
Q(Lde)
Q(Rg)
Q(Re)
Q(Rdg)
Q(Rde)

D(	localaff,			G,		5.0,		"Gap open penalty.")
D(	localaff,			E,		0.23,		"Gap extend penalty.")

D(	localaffnuc,		G,		4.54,		"Gap open penalty.")
D(	localaffnuc,		E,		0.22,		"Gap extend penalty.")

D(	localaffnuc,		G,		4.0,		"Gap open penalty.")
D(	localaffnuc,		E,		0.3,		"Gap extend penalty.")

D(	globalaff,			g,		6.75,		"Gap open penalty.")
D(	globalaff,			e,		0.22,		"Gap extend penalty.")

D(	globalaffnuc,		g,		4.0,		"Gap open penalty.")
D(	globalaffnuc,		e,		0.3,		"Gap extend penalty.")

D(	globaldaff,			g,		6.09,		"Gap open penalty.")
D(	globaldaff,			e,		1.33,		"Gap extend penalty.")
D(	globaldaff,			dg,		7.06,		"Alt. gap open penalty.")
D(	globaldaff,			de,		0.63,		"Alt. gap extend penalty.")

D(	globaltermaff,		g,		6.36,		"Gap open penalty.")
D(	globaltermaff,		e,		0.29,		"Gap extend penalty.")
D(	globaltermaff,		tg,		1.91,		"Term gap open penalty.")
D(	globaltermaff,		te,		0.12,		"Term gap extend penalty.")

D(	global,				g,		5.3712,		"Internal gap open penalty.")
D(	global,				e,		1.6220,		"Internal gap extend penalty.")
D(	global,				dg,		7.1494,		"Internal alt. gap open penalty.")
D(	global,				de,		0.2215,		"Internal alt. gap extend penalty.")
D(	global,				tg,		2.0132,		"Terminal gap open penalty.")
D(	global,				te,		0.8336,		"Terminal gap extend penalty.")
D(	global,				tdg,	7.9865,		"Terminal alt. gap open penalty.")
D(	global,				tde,	0.0740,		"Terminal alt. gap extend penalty.")

// --g 4.54  --e 2.0  --tg 3.68 --te 2.13 --dg 7.66  --de 0.44  --tdg 8.03  --tde 0.33
D(	globalnuc,			g,		4.54,		"Internal gap open penalty.")
D(	globalnuc,			e,		2.0,		"Internal gap extend penalty.")
D(	globalnuc,			dg,		7.66,		"Internal alt. gap open penalty.")
D(	globalnuc,			de,		0.44,		"Internal alt. gap extend penalty.")
D(	globalnuc,			tg,		3.68,		"Terminal gap open penalty.")
D(	globalnuc,			te,		2.13,		"Terminal gap extend penalty.")
D(	globalnuc,			tdg,	8.03,		"Terminal alt. gap open penalty.")
D(	globalnuc,			tde,	0.33,		"Terminal alt. gap extend penalty.")

#undef C
#undef A
#undef M
#undef P
#undef D
#undef Q
