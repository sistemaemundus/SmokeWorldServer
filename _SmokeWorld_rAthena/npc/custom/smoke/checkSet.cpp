//===Criado por Emundus
//= dispbottom dos conjuntos ativos no personagem.
-	script	checkSet	-1,{
	OnInit:
		bindatcmd "checkset",strnpcinfo(0) + "::OnAtcommand";
		end;
	OnAtcommand:
		.@ativo = 0;

		// =========================
		// GODLIKE
		// =========================

		if (isequipped(840055) && isequipped(840056) && isequipped(840057)) {
			dispbottom "| GodLike - Tier I |",0xFFFF00;
			dispbottom "ATK +15% | MATK +15%",0xFFFF00;
			dispbottom "Dano em Boss +8%",0xFFFF00;
			.@ativo = 1;
		}
		else if (isequipped(840071) && isequipped(840073) && isequipped(840075)) {
			dispbottom "| GodLike - Tier II |",0xFFFF00;
			dispbottom "ATK +25% | MATK +25%",0xFFFF00;
			dispbottom "Dano em Boss +12%",0xFFFF00;
			.@ativo = 1;
		}
		else if (isequipped(840072) && isequipped(840074) && isequipped(840076)) {
			dispbottom "| GodLike - Tier III |",0xFFFF00;
			dispbottom "ATK +35% | MATK +35%",0xFFFF00;
			dispbottom "Dano em Boss +18%",0xFFFF00;
			.@ativo = 1;
		}

		// =========================
		// PHOENIX
		// =========================

		if (isequipped(840058) && isequipped(840059) && isequipped(840060)) {
			dispbottom "| Phoenix - Tier I |",0xFF3300;
			dispbottom "ATK +35% | MATK +35%",0xFF3300;
			dispbottom "Dano em Boss +15%",0xFF3300;
			.@ativo = 1;
		}
		else if (isequipped(840077) && isequipped(840078) && isequipped(840079)) {
			dispbottom "| Phoenix - Tier II |",0xFF3300;
			dispbottom "ATK +50% | MATK +50%",0xFF3300;
			dispbottom "Dano em Boss +22%",0xFF3300;
			.@ativo = 1;
		}
		else if (isequipped(840080) && isequipped(840081) && isequipped(840082)) {
			dispbottom "| Phoenix - Tier III |",0xFF3300;
			dispbottom "ATK +65% | MATK +65%",0xFF3300;
			dispbottom "Dano em Boss +28%",0xFF3300;
			.@ativo = 1;
		}

		// =========================
		// AZUR
		// =========================

		if (isequipped(840061) && isequipped(840062) && isequipped(840063)) {
			dispbottom "| Azur - Tier I |",0x3399FF;
			dispbottom "ATK +70% | MATK +70%",0x3399FF;
			dispbottom "Dano em Boss +25%",0x3399FF;
			.@ativo = 1;
		}
		else if (isequipped(840083) && isequipped(840084) && isequipped(840085)) {
			dispbottom "| Azur - Tier II |",0x3399FF;
			dispbottom "ATK +70% | MATK +70%",0x3399FF;
			dispbottom "Dano em Boss +25%",0x3399FF;
			.@ativo = 1;
		}
		else if (isequipped(840086) && isequipped(840087) && isequipped(840088)) {
			dispbottom "| Azur - Tier III |",0x3399FF;
			dispbottom "ATK +105% | MATK +105%",0x3399FF;
			dispbottom "Dano em Boss +38%",0x3399FF;
			.@ativo = 1;
		}

		// =========================
		// ASCENSION
		// =========================

		if (isequipped(840064) && isequipped(840065) && isequipped(840066)) {
			dispbottom "| Ascension - Tier I |",0x9900FF;
			dispbottom "ATK +90% | MATK +90%",0x9900FF;
			dispbottom "Dano em Boss +35%",0x9900FF;
			.@ativo = 1;
		}
		else if (isequipped(840089) && isequipped(840090) && isequipped(840091)) {
			dispbottom "| Ascension - Tier II |",0x9900FF;
			dispbottom "ATK +120% | MATK +120%",0x9900FF;
			dispbottom "Dano em Boss +48%",0x9900FF;
			.@ativo = 1;
		}
		else if (isequipped(840092) && isequipped(840093) && isequipped(840094)) {
			dispbottom "| Ascension - Tier III |",0x9900FF;
			dispbottom "ATK +140% | MATK +140%",0x9900FF;
			dispbottom "Dano em Boss +55%",0x9900FF;
			.@ativo = 1;
		}

		if (!.@ativo)
			dispbottom "Sem conjuntos Smoke ativos.",0xAAAAAA;

		end;
}