/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>

char No_Effect[] = "Hmm...No effect!\n";
char None_Owned[] = "None owned!\n";
char D_010E[] = {/*colors masks*/
	(1<<6)|(1<<5)|(1<<3)|(1<<0),/*truth*/
	(1<<6)|(1<<4)|(1<<3)|(1<<1),/*love*/
	(1<<6)|(1<<5)|(1<<4)|(1<<2) /*courage*/
};

void C_01E1()
{
	int bp_10, bp_02;
	char bp_12[12];
	char bp_04;

	if(Combat._charaX[activeChara] != 5 || Combat._charaY[activeChara] != 5 || Altar == -1) {
		u4_puts(No_Effect);
		return;
	}
	u4_puts(/*D_0080*/"\nThere are holes for 4 stones. What colors:\n");
	bp_04 = 0;
	for(bp_02 = 1; bp_02 <= 4; bp_02++) {
		u4_putc(bp_02 + 'A' - 1); u4_putc(':');
		u4_gets(bp_12, 11);
		Gra_CR();
		for(bp_10 = 7; bp_10 >= 0; bp_10--) {
			if(strnicmp(Shrines[bp_10], bp_12, 12) == 0)
				break;
		}
		if(bp_10 == -1 || !TST_MSK(Party.mStones, bp_10)) {
			if(*bp_12 != '\0')
				u4_puts(None_Owned);
			return;
		}
		if((1 << bp_10) & bp_04) {
			u4_puts(/*D_00AD*/"Already used!\n");
			return;
		}
		bp_04 |= (1 << bp_10);
	}
	if(D_010E[Altar] != bp_04) {
		u4_puts(No_Effect);
		return;
	}
	switch(Altar) {
		case 0:
			if(TST_MSK(Party.mItems, 7)) {
				u4_puts(No_Effect);
				return;
			}
			SET_MSK(Party.mItems, 7);
		break;
		case 1:
			if(TST_MSK(Party.mItems, 6)) {
				u4_puts(No_Effect);
				return;
			}
			SET_MSK(Party.mItems, 6);
		break;
		case 2:
			if(TST_MSK(Party.mItems, 5)) {
				u4_puts(No_Effect);
				return;
			}
			SET_MSK(Party.mItems, 5);
		break;
	}
	u4_puts(/*D_00BC*/"Thou doth find one third of the Three Part Key!\n");
}

char *D_0284[] = {
	/*D_0111*/"Truth",
	/*D_0117*/"Love",
	/*D_011C*/"Courage",
	/*D_0124*/"Truth and Love",
	/*D_0133*/"Love and Courage",
	/*D_0144*/"Courage and Truth",
	/*D_0156*/"Truth, Love and Courage",
	/*D_016E*/"\nA voice rings out:  What Virtue exists independently of Truth, Love and Courage"
};

/*use stone(s)*/
USE_Stones() {
	int bp_02;

	if(Party.mStones) {
		char bp_10[14];
		if(CurMode != MOD_COM_ROOM && CurMode != MOD_DUNGEON)
			u4_puts(/*D_01BF*/"No place to Use them!\n");
		if(CurMode == MOD_DUNGEON) {
			if(tile_cur != 0xb0 || Party._loc != 0x18) {
				u4_puts(No_Effect);
				return;
			}
			if(Party._z != 7)
				u4_puts(/*D_01D6*/"\nAs thou doth approach, a voice rings out: What virtue dost stem from ");
			u4_puts(D_0284[Party._z]);
			u4_puts(/*D_021D*/"?\n\n");
			u4_gets(bp_10, 13);
			Gra_CR();
			if(strnicmp(bp_10, D_Virtues[Party._z], 14)) {
C_03A1:
				if(bp_10[0])
					u4_puts(No_Effect);
				return;
			}
			u4_puts(/*D_0221*/"\nThe Voice says: Use thy Stone.\n\nColor:\n");
			u4_gets(bp_10, 11);
			Gra_CR();
			bp_02 = 7;
			while(
				strnicmp(bp_10, Shrines[bp_02], 12) &&
				--bp_02 >= 0
			);
			if(bp_02 == -1)
				goto C_03A1;
			if(!TST_MSK(Party.mStones, bp_02)) {
				u4_puts(/*D_024A*/"\nYou have none!\n\n");
				return;
			}
			if(Party._z != bp_02) {
				u4_puts(No_Effect);
				return;
			}
			if(Party._z == 7) {
				C_31F4();/*last phase of game*/
				return;
			}
			D_8742._map.x8x8x8[Party._z][Party._y][Party._x] = 0x20;
			u4_puts(/*D_025C*/"\nThe altar changes before thyne eyes!\n");
		} else {
			C_01E1();
		}
	} else {
		u4_puts(None_Owned);
	}
}

/*use key(s)*/
C_044C() {
	if(
		((Party.mItems >> 7) & 1) |
		((Party.mItems >> 6) & 1) |
		((Party.mItems >> 5) & 1)
	)
		u4_puts("No place to Use them!\n");
	else
		u4_puts(None_Owned);
}

/*use bell*/
C_0487() {
	if(!TST_MSK(Party.mItems, 4)) {
		u4_puts(None_Owned);
		return;
	}
	if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9) {
		u4_puts(No_Effect);
		return;
	}
	SET_MSK(Party.mItems, 12);
	u4_puts("The Bell rings on and on!\n");
}

/*use book*/
C_04C0() {
	if(!TST_MSK(Party.mItems, 3)) {
		u4_puts(None_Owned);
		return;
	}
	if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9 ||
		!TST_MSK(Party.mItems, 12)
	) {
		u4_puts(No_Effect);
		return;
	}
	SET_MSK(Party.mItems, 11);
	u4_puts("The words resonate with the ringing!\n");
}

/*use candle*/
C_0501() {
	if(!TST_MSK(Party.mItems, 2)) {
		u4_puts(None_Owned);
		return;
	}
	if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9 ||
		!TST_MSK(Party.mItems, 11)
	) {
		u4_puts(No_Effect);
		return;
	}
	SET_MSK(Party.mItems, 10);
	u4_puts("As you light the Candle the Earth Trembles!\n");
	sound(6);
	shakefx();
}

/*use horn*/
C_0553() {
	if(!TST_MSK(Party.mItems, 8)) {
		u4_puts(None_Owned);
		return;
	}
	if(Party._loc != 0) {
		u4_puts(No_Effect);
		return;
	}
	u4_puts("The Horn sounds an eerie tone!\n");
	spell_sta = 1;
	spell_cnt = 10;
	dspl_Stats();
}

/*use belt*/
USE_Belt() {
    if(!TST_MSK(Party.mItems, 15)) {
        u4_puts(None_Owned);
        return;
    }
    u4_puts("The Belt glows and hums gently!\n");
    spell_sta = 'B';
    spell_cnt = 20;
    dspl_Stats();
}

/*use orb*/
USE_Orbs() {
    if(!TST_MSK(Party.mItems2, 5) && !TST_MSK(Party.mItems2, 7) && !TST_MSK(Party.mItems2, 9)) {
        u4_puts(None_Owned);
        return;
    }
    if(Party._loc == 44) {
        u4_puts("\nYou place the Orb onto the altar!\n");
        SET_MSK(Party.mItems2, 6);
        RST_MSK(Party.mItems2, 5);
        SET_MSK(Party.mItems2, 11);/*Marks that Orb is in the Oracle's altar*/
    } else if(Party._loc == 45) {
        u4_puts("\nYou place the Orb onto the altar!\n");
        SET_MSK(Party.mItems2, 8);
        RST_MSK(Party.mItems2, 7);
        SET_MSK(Party.mItems2, 12);/*Marks that Orb is in the Oracle's altar*/
    } else if(Party._loc == 46) {
        u4_puts("\nYou place the Orb onto the altar!\n");
        SET_MSK(Party.mItems2, 10);
        RST_MSK(Party.mItems2, 9);
        SET_MSK(Party.mItems2, 13);/*Marks that Orb is in the Oracle's altar*/
    } else {
        u4_puts(No_Effect);
        return;
    }
    dspl_Stats();
}

/*use wheel*/
C_058C() {
    if(!TST_MSK(Party.mItems, 9)) {
        u4_puts(None_Owned);
        return;
    }
    if(Party._loc != 0 || Party._tile > TIL_ShipS_13 || Party._ship != 50) {
        u4_puts(No_Effect);
        return;
    }
    u4_puts("Once mounted, the Wheel glows with a blue light!\n");
    Party._ship = 99;
    dspl_Stats();
}

/*use ring*/
USE_Ring() {
    if(!TST_MSK(Party.mItems2, 0)) {
        u4_puts(None_Owned);
        return;
    }
    if((CurMode == MOD_COM_ROOM && Combat._charaX[activeChara] == 5 && Combat._charaY[activeChara] == 5 && Tomb == 2) || (Party._loc - 0x2e == 0)) {
        u4_puts("\nYou place the Ring of Exodus into the Altar....\n");
        SET_MSK(Party.mItems2, 1);
        /*Should this stay here or should it match the Wand and the Ring? Match it for now*/
        RST_MSK(Party.mItems2, 0);
        Crypt_Exit(Party._loc);
    }
    else if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9) {
        u4_puts("\nThe Ring glows brighter and lets out a flash of light!\n");
    
        /* All Party Damage */
        Party_Damage(100);
        /*removed as could cause negative MP*/
        /*MP_drain();*/
        Gra_09();
        spell_sta = 'R';
        spell_cnt = 7;
        dspl_Stats();
        
    } else {
        u4_puts("\nYou cast the Ring of Exodus into the Abyss!\n");
        SET_MSK(Party.mItems2, 1);
        Big_Karma_Inc();
        /*moved the mask to here so Ring is only removed from inventory when cast into Abyss */
        RST_MSK(Party.mItems2, 0);
    }
}

Skull_Kill() {
    int bp_02;
    if(CurMode >= MOD_COMBAT) {
        for(bp_02 = 31; bp_02 >= 0; bp_02 --) {
            if(D_8742._npc._tile[bp_02] != TIL_5E)
                D_8742._npc._tile[bp_02] = D_8742._npc._gtile[bp_02] = 0;
        }
        for(bp_02 = 15; bp_02 >= 0; bp_02 --) {
            if(Fighters._tile[bp_02] != TIL_5E)
                Fighters._tile[bp_02] = Fighters._gtile[bp_02] = 0;
        }
    } else {
        for(bp_02 = (Party._loc == 0)?7:31; bp_02 >= 0; bp_02 --) {
            if(D_8742._npc._tile[bp_02] != TIL_5E)
                D_8742._npc._tile[bp_02] = D_8742._npc._gtile[bp_02] = 0;
        }
    }
}

/*use skull*/
USE_Skull() {
	int bp_02;

	if(!TST_MSK(Party.mItems, 0)) {
		u4_puts(None_Owned);
		return;
	}
    if((CurMode == MOD_COM_ROOM && Combat._charaX[activeChara] == 5 && Combat._charaY[activeChara] == 5 && Tomb == 0) || (Party._loc - 0x2c == 0)) {
        u4_puts("\nYou place the Skull of Mondain onto the altar....\n");
        SET_MSK(Party.mItems, 1);
        /*Should this stay here or should it match the Wand and the Ring? Match it for now*/
        RST_MSK(Party.mItems, 0);
        Crypt_Exit(Party._loc);
    }
	else if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9) {
		u4_puts("\nYou hold the evil Skull of Mondain the Wizard aloft....\n");
        Big_Shake();
        Skull_Kill();
        /*C_06B2:*/
        t_callback();
        karma_dec((char *)&(Party._hones), 5);
        karma_dec((char *)&(Party._compa), 5);
        karma_dec((char *)&(Party._valor), 5);
        karma_dec((char *)&(Party._justi), 5);
        karma_dec((char *)&(Party._sacri), 5);
        karma_dec((char *)&(Party._honor), 5);
        karma_dec((char *)&(Party._spiri), 5);
        karma_dec((char *)&(Party._humil), 5);
        dspl_Stats();
        
	} else {
        u4_puts("\nYou cast the Skull of Mondain into the Abyss!\n");
		SET_MSK(Party.mItems, 1);
        Big_Karma_Inc();
        /*Should this stay here or should it match the Wand and the Ring? Match it for now*/
        RST_MSK(Party.mItems, 0);
	}
}

/*use wand*/
USE_Wand() {
    int bp_02;
    register int si;

    
    if(!TST_MSK(Party.mItems, 13)) {
        u4_puts(None_Owned);
        return;
    }

    if((CurMode == MOD_COM_ROOM && Combat._charaX[activeChara] == 5 && Combat._charaY[activeChara] == 5 && Tomb == 1) || (Party._loc - 0x2d == 0)) {
        u4_puts("\nYou place the Wand of Minax into the Altar....\n");
        SET_MSK(Party.mItems, 14);
        /*Should this stay here or should it match the Wand and the Ring? Match it for now*/
        RST_MSK(Party.mItems, 13);
        Crypt_Exit(Party._loc);
    }
    else if(Party._loc != 0 || Party._x != 0xe9 || Party._y != 0xe9) {
        u4_puts("\nYou raise the enscorled Wand of Minax the Enchantress before thee....\n");
        USE_WandMagic();
        /* do we need this callback? */
        t_callback();
    } else {
        u4_puts("\nYou cast the Wand of Minax into the Abyss!\n");
        SET_MSK(Party.mItems, 14);
        Big_Karma_Inc();
        /*put the mask here so the wand is only destroyed when cast into the Abyss or entombed in the Crypt */
        RST_MSK(Party.mItems, 13);
    }
}

Big_Shake() {
    sound(6); shakefx();
    Gra_09();
    sound(6); shakefx();
    Gra_09();
    sound(6); shakefx();
    return;
}

Big_Karma_Inc() {
    karma_inc((char *)&(Party._hones), 10);
    karma_inc((char *)&(Party._compa), 10);
    karma_inc((char *)&(Party._valor), 10);
    karma_inc((char *)&(Party._justi), 10);
    karma_inc((char *)&(Party._sacri), 10);
    karma_inc((char *)&(Party._honor), 10);
    karma_inc((char *)&(Party._spiri), 10);
    karma_inc((char *)&(Party._humil), 10);
    Big_Shake();
    return;
}

USE_WandMagic() {
    register int si;
    int lat1,long1,lat2,long2,wandx,wandy,spell_power;

    if(Party._tile < TIL_HorseW_14 || Party._tile == TIL_18) {
        w_Failed();
        return;
    }
    if(!C_6409())
        return;

    u4_puts("\nIncantation:\n");
    lat1 = USE_Incant(lat1);
    lat2 = USE_Incant(lat2);
    long1 = USE_Incant(long1);
    long2 = USE_Incant(long2);
    u4_puts("\n");
    
    wandy = ((lat1 * 16) + lat2);
    wandx = ((long1 * 16) + long2);
    spell_power = (Party._y + Party._x);
    spell_power -= (wandy + wandx);
    spell_power = u4_abs(spell_power)/4;
    if(spell_power <= 0)
        spell_power = 1;
    
    if(!USE_WandCast(spell_power))
        return;
    
    Party_Damage(spell_power * 4);
    /*removed as could cause negative MP*/
    /*MP_drain();*/
    
    Party._y = wandy;
    Party._x = wandx;
    u4_puts(/*D_1777*/"\nTeleported!\n\n");
    C_26B6();
    return;
}

USE_Incant(bp04) {
    bp04 = AskLetter(0, 'A', 'P');
    bp04 -= 'A';
    if(bp04 < 0 || bp04 > 16){
        return;
    } else {
        u4_puts(D_Incantations[bp04]);
        return bp04;
    }
}

USE_WandCast(spell_pow) {
    sound(10, spell_pow);
    Gra_09(); sound(9, 7+0x60); Gra_09();
    if(spell_sta == 'N') {
        w_Failed();
        return 0;
    }
    return 1;
}

struct {
	char *_00;
	void (*_02)();
} D_0434[] = {
	{/*D_03D5*/"stone",  USE_Stones},
	{/*D_03DB*/"stones", USE_Stones},
	{/*D_03E2*/"bell",   C_0487},
	{/*D_03E7*/"book",   C_04C0},
	{/*D_03EC*/"candle", C_0501},
	{/*D_03F3*/"key",    C_044C},
	{/*D_03F7*/"keys",   C_044C},
	{/*D_03FC*/"horn",   C_0553},
    {/*D_03FC*/"ring",   USE_Ring},
	{/*D_0401*/"wheel",  C_058C},
	{/*D_0407*/"skull",  USE_Skull},
    {/*D_0407*/"wand",   USE_Wand},
    {/*D_0407*/"belt",   USE_Belt},
    {/*D_0407*/"orb",   USE_Orbs},
	{/*D_040D*/"",       0}
};

CMD_Use() {
	register int si;
	char bp_0e[12];

    if(CurMode == MOD_SHRINE) {
        u4_puts("Give what item:\n");
    }
    else {
        u4_puts("Use which item:\n");
    }
	u4_gets(bp_0e, 11);
	Gra_CR();
	for(si = 0; D_0434[si]._00[0]; si++) {
		if(strnicmp(D_0434[si]._00, bp_0e, 12) == 0) {
			(*(D_0434[si]._02))();
			return;
		}
	}
	u4_puts("Not a Usable item!\n");
}
