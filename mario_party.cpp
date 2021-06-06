#define _CRT_SECURE_NO_WARNINGS
#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

TimerID timer1, timer2, timer3, timer4, timer5, timer6, timer7, timer8, timer9;
SceneID gamescene[11];
int coin[4] = { 10,10,10,10 };
int star[4] = { 0 };
int timer7check = 0;
ObjectID player[4], obstacle[2], item[3], charicon[4], mainstar[12];
ObjectID dice, inventory, backspace;
ObjectID coincloud[4],charr[4], arrow[4];
ObjectID square[50], squarecheck[4], squarec[4], ministart;
ObjectID playerdice[2], aidice[6], minichar[4], mini3start, mini3end, multiple[4];
ObjectID pico[30], fakepico[10], game4start, game4answer[4], mini4check[4], awardstart, awardchar[4], awardstar[8];
int landx[34] = {1115,1000,900,900,900,1000,1115,1115,1115,1000,900,800,695,695,695,695,695,600,490,380,270,165,165,165,265,380,485,485,485,380,275,160};
int landy[34] = {140,140,140,230,320,320,320,410,500,500,500,500,500,410,320,230,140,140,140,140,140,230,320,320,320,320,410,500,500,500,500};
int playerlocate[4] = {0,0,0,0};
int playeritem[3] = { 0,0,0 };
int aiitem[4][3];
int cloudlocationx[4] = { 300,600,900,600 };
int cloudlocationy[4] = { 320,564,320,76 };
int turn = 0;
int startcheck = 0;
int movecheck = 0;
int mini2check[4] = {0,0,0,0};
int squareanswer[4] = {0,0,0,0};
int playervalue, aitempvalue, aivalue;
int picolocate[30] = { 0 };
int picolocatey[30] = { 0 };
int fakepicolocate[10] = { 0 };
int fakepicolocatey[10] = { 0 };
int picospeed[30] = {0};
int fakepicospeed[10] = { 0 };
int game4correct, fakepicocorrect, game4press;
int game4check[4] = {0};
int unluck[4] = { 0,0,0,0 };
int minigamewin[4] = { 0,0,0,0 };
void minigame1(int t) {
	locateObject(charr[0], gamescene[1], cloudlocationx[t], cloudlocationy[t]);
	int a = rand() % 4;
	locateObject(charr[1], gamescene[1], cloudlocationx[a], cloudlocationy[a]);
	int b = rand() % 4;
	locateObject(charr[2], gamescene[1], cloudlocationx[b], cloudlocationy[b]);
	int c = rand() % 4;
	locateObject(charr[3], gamescene[1], cloudlocationx[c], cloudlocationy[c]);
	if (t == a || t == b || t == c) {
		showMessage("코인 획득에 실패하셨습니다");
	}
	else {
		switch (t) {
		case 0: coin[0] += 3; showMessage("코인을 3개 획득했습니다."); break;
		case 1: coin[0] += 5; showMessage("코인을 5개 획득했습니다."); break;
		case 2: coin[0] += 3; showMessage("코인을 3개 획득했습니다."); break;
		case 3: coin[0] += 10; showMessage("코인을 10개 획득했습니다."); minigamewin[0]++; break;
		}
	}
	if (a == t || a == b || a == c) {

	}
	else {
		switch (a) {
		case 0: coin[1] += 3; break;
		case 1: coin[1] += 5; break;
		case 2: coin[1] += 3; break;
		case 3: coin[1] += 10; minigamewin[1]++; break;
		}
	}
	if (b == t || b == a || b == c) {

	}
	else {
		switch (b) {
		case 0: coin[2] += 3; break;
		case 1: coin[2] += 5; break;
		case 2: coin[2] += 3; break;
		case 3: coin[2] += 10; minigamewin[2]++; break;
		}
	}
	if (c == t || c == a || c == b) {

	}
	else {
		switch (c) {
		case 0: coin[3] += 3; break;
		case 1: coin[3] += 5; break;
		case 2: coin[3] += 3; break;
		case 3: coin[3] += 10; minigamewin[3]++; break;
		}
	}
	startTimer(timer1);
	movecheck = 1;
}
void minigame2() {
	for (int i = 0;i < 50;i++) {
		int a = rand() % 4;
		if (a == 0) {
			setObjectImage(square[i], "Images/K-029.png");
			squareanswer[0]++;
		}
		if (a == 1) {
			setObjectImage(square[i], "Images/K-030.png");
			squareanswer[1]++;
		}
		if (a == 2) {
			setObjectImage(square[i], "Images/K-031.png");
			squareanswer[2]++;
		}
		if (a == 3) {
			setObjectImage(square[i], "Images/K-032.png");
			squareanswer[3]++;
		}
	}
	setTimer(timer2, 3.0);
	startTimer(timer2);
}
void minigame2wincheck() {
	int squaresort[4] = {0,0,0,0};
	int temp = 0;
	for (int i = 0;i < 4;i++) {
		squaresort[i] = squareanswer[i];
	}
	for (int i = 3;i > 0;i--) {
		for (int j = 0;j < i;j++) {
			if (squaresort[j] > squaresort[j + 1]) {
				temp = squaresort[j];
				squaresort[j] = squaresort[j + 1];
				squaresort[j + 1] = temp;
			}
		}
	}
	int a = mini2check[0];
	int b = squareanswer[a-1];
	if (b == squaresort[0]) { coin[0] += 10; minigamewin[0]++; showMessage("코인 10개를 획득하셨습니다."); }
	else if (b == squaresort[1]) { coin[0] += 7; showMessage("코인 7개를 획득하셨습니다."); }
	else if (b == squaresort[2]) { coin[0] += 3; showMessage("코인 3개를 획득하셨습니다."); }
	else { showMessage("코인 획득에 실패하셨습니다."); }
}
void mini2aiwincheck() {
	int squaresort[4] = { 0,0,0,0 };
	int temp = 0;
	for (int i = 0;i < 4;i++) {
		squaresort[i] = squareanswer[i];
	}
	for (int i = 3;i > 0;i--) {
		for (int j = 0;j < i;j++) {
			if (squaresort[j] > squaresort[j + 1]) {
				temp = squaresort[j];
				squaresort[j] = squaresort[j + 1];
				squaresort[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i < 4; i++) {
		int a = mini2check[i];
		int b = squareanswer[a - 1];
		if (b == squaresort[0]) { coin[i] += 10; minigamewin[i]++; }
		else if (b == squaresort[1]) { coin[i] += 7;}
		else if (b == squaresort[2]) { coin[i] += 3;}
		else {}
	}
	startTimer(timer3);
}
void minigame3() {
	startTimer(timer4);
}
void game3wincheck() {
	if (playervalue > aivalue) {
		showMessage("승리하셨습니다.\n코인 10개를 획득하셨습니다.");
		coin[0] += 10;
		minigamewin[0]++;
	}
	else if (playervalue == aivalue) {
		showMessage("무승부입니다.\n 플레이어는 코인 5개. \nai는 코인 3개를 획득합니다.");
		coin[0] += 5;
		for (int i = 1; i < 4; i++) {
			coin[i] += 3;
		}
	}
	else {
		showMessage("패배하셨습니다.\n코인을 획득하지 못하셨습니다.");
		for (int i = 1; i < 4; i++) {
			coin[i] += 5;
			minigamewin[i]++;
		}
	}
	startTimer(timer5);
}
void game4() {
	int a = rand() % 4 + 27;
	game4correct = a;
	int b = rand() % 3 + 2;
	fakepicocorrect = b;
	for (int i=0; i < a;i++) {
		picospeed[i] = rand() % 45 + 10;
	}
	for (int i = 0;i < b;i++) {
		fakepicospeed[i] = rand() % 45 + 10;
	}
	startTimer(timer6);
	startTimer(timer7);
}
void game4wincheck() {
	if (game4correct > 20) { game4correct -= 26; }
	else{}
	if (game4check[0] == game4correct) {
		showMessage("코인을 15개 획득하셨습니다.");
		coin[0] += 15;
		minigamewin[0]++;
	}
	else {
		showMessage("코인 획득에 실패하셨습니다.");
	}
}
void game4aiwincheck() {
	if (game4correct>20) {
		game4correct -= 26;
	}
	else{}
	for (int i = 1;i < 4;i++) {
		if (game4check[i] == game4correct) { coin[i] += 15; minigamewin[i]++; }
		else {
			coin[i] += 0;
		}
	}
	startTimer(timer8);
}
void enterboardgame() {
	if (turn == 10) { enterScene(gamescene[10]); showMessage("시상식입니다.\n가장 불운한 플레이어는 스타를 하나 획득합니다.\n미니게임에서 가장 많이 이긴 플레이어는 스타를 하나 획득합니다."); }
	else { 
		int a = rand() % 4 + 1;
		enterScene(gamescene[a]);
		if (a == 1) { showMessage("선택한 칸에 있는 코인 수 만큼 코인을 얻습니다.\n다른 플레이어와 같은 칸을 선택할 경우 코인을 얻지 못합니다."); }
		if (a == 2) { showMessage("가장 적은 색이 칠해진 타일을 아래에서 골라주세요\n1등의 경우 코인 10개. 2등의 경우 코인 7개\n 3등의 경우 코인 3개. 4등은 아무것도 얻지 못합니다.\nstart버튼을 눌러 시작해주세요\3초 안에 고르지 않으면 ai가 고르고 남는걸 골라야 합니다."); }
		if (a == 3) { showMessage("주사위를 굴려 ai플레이어의 총합보다 높은 주사위를 굴려주세요\nai의 경우 각 주사위의 최댓값은 3. 플레이어는 6입니다.\start버튼을 눌러 시작해주세요"); }
		if (a == 4) { showMessage("화면을 지나가는 파란색 키노피오의 수를 아래 타일에서 맞춰주세요\n 1등의 경우에만 코인 15개를 획득합니다.\start버튼을 눌러 시작해주세요\n15초안에 고르지 않으면 ai가 고르고 남는걸 골라야 합니다."); }
	}
}
void charmove(int s, int y, int t) {
	if (aiitem[s][0]) {
		t += 3;
		aiitem[s][0]--;
	}
	if (aiitem[s][1]) {
		t += 5;
		aiitem[s][1]--;
	}
	if (aiitem[s][2]) {
		t += 5;
		aiitem[s][2]--;
	}
	int i = rand() % 6 + 1 + t;
	for (i; i != 0; i--) {
		y++;
		playerlocate[s]++;
		locateObject(player[s], gamescene[0], landx[y], landy[y]);
		if (playerlocate[s] == 31) {
			if (coin[s] >= 30) {
				star[s]++;
				coin[s] -= 30;
			}
			if(star[s] == 1){
				if (s == 0) { showObject(mainstar[0]); }
				else if (s == 1) { showObject(mainstar[3]); }
				else if (s == 2) { showObject(mainstar[6]); }
				else if (s == 3) { showObject(mainstar[9]); }
			}
			else if (star[s] == 2) {
				if (s == 0) { showObject(mainstar[1]); }
				else if (s == 1) { showObject(mainstar[4]); }
				else if (s == 2) { showObject(mainstar[7]); }
				else if (s == 3) { showObject(mainstar[10]); }
			}
			else if (star[s] == 3) {
				if (s == 0) { showObject(mainstar[2]); }
				else if (s == 1) { showObject(mainstar[5]); }
				else if (s == 2) { showObject(mainstar[8]); }
				else if (s == 3) { showObject(mainstar[11]); }
			}
			playerlocate[s] = 0;
			y = 0;
			locateObject(player[s], gamescene[0], landx[y], landy[y]);
		}
	}
	if (playerlocate[s] == 1 || playerlocate[s] == 7 || playerlocate[s] == 25) {
		int a = rand() % 3;
		if (s == 0) { 
			playeritem[a]++;
			switch (a) {
			case 0: showMessage("대시 버섯을 획득하셨습니다."); break;
			case 1: showMessage("트리플 대시버섯을 획득하셨습니다."); break;
			case 2: showMessage("황금 대시버섯을 획득하셨습니다."); break;
			}
		}
		else { aiitem[s][a]++; }
	}
	else if (playerlocate[s] == 10 || playerlocate[s] == 19 || playerlocate[s] == 24) {
		coin[s] -= 3;
		unluck[s] += 1;
	}
	else if (playerlocate[s] == 17) {
		coin[s] = 0;
		unluck[s] += 3;
	}
	else if (playerlocate[s] == 14) {
		if (s == 0) { for (int i = 0; i < 3; i++) { playeritem[i]++;  showMessage("모든 아이템을 하나씩 획득 하셨습니다."); } }
		else { for (int i = 0;i < 3;i++)aiitem[s][i]++; }
	}
	else { coin[s] += 3; }
	if (s == 3) {
		startTimer(timer9);
		turn++;
	}
}
void mousecallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == 5) {
		charmove(0, playerlocate[0], 0);
		charmove(1, playerlocate[1], 0);
		charmove(2, playerlocate[2], 0);
		charmove(3, playerlocate[3], 0);
	}
	else if (object == 6) {
		hideObject(dice);
		hideObject(inventory);
		showObject(item[0]);
		showObject(item[1]);
		showObject(item[2]);
		showObject(backspace);
		showMessage("대시버섯은 3칸 추가 이동.\n트리플 대시버섯은 5칸 추가 이동.\n황금 버섯은 7칸 추가 이동입니다.");
	}
	else if (object == 7 && playeritem[0]>0) {
		playeritem[0]--;
		charmove(0, playerlocate[0], 3);
		charmove(1, playerlocate[1], 0);
		charmove(2, playerlocate[2], 0);
		charmove(3, playerlocate[3], 0);
		showMessage("대시버섯을 사용했습니다.");
	}
	else if (object == 8 && playeritem[1] > 0) {
		playeritem[1]--;
		charmove(0, playerlocate[0], 5);
		charmove(1, playerlocate[1], 0);
		charmove(2, playerlocate[2], 0);
		charmove(3, playerlocate[3], 0);
		showMessage("트리플 대시버섯을 사용했습니다.");
	}
	else if (object == 9 && playeritem[2] > 0) {
		playeritem[2]--;
		charmove(0, playerlocate[0], 7);
		charmove(1, playerlocate[1], 0);
		charmove(2, playerlocate[2], 0);
		charmove(3, playerlocate[3], 0);
		showMessage("황금대시버섯을 사용했습니다.");
	}
	else if (object == 10) {
		showObject(dice);
		showObject(inventory);
		hideObject(item[0]);
		hideObject(item[1]);
		hideObject(item[2]);
		hideObject(backspace);
	}
	else if ((object == 19 || object == 20 || object==21 || object==22) && movecheck == 0) {
		minigame1(object - 19);
	}
	else if (object == 77) {
		minigame2();
	}
	else if ((object == 73 || object == 74 || object == 75 || object == 76) && startcheck == 0) {
		startcheck++;
		mini2check[0] = object - 72;
		showObject(squarec[object - 73]);
		minigame2wincheck();
	}
	else if (object == 94) {
		minigame3();
	}
	else if (object == 95) {
		stopTimer(timer4);
		for (int i = 0;i < 2;i++) {
			char buf[50];
			int a = rand() % 6 + 1;
			sprintf(buf, "Images/dice%d.png", a);
			setObjectImage(playerdice[i], buf);
			if (i == 0) { playervalue += a; }
			else if (i == 1) { playervalue *= a; }
		}
		for (int i = 0; i < 6; i++) {
			char buf[50];
			int b = rand() % 3 + 1;
			sprintf(buf, "Images/dice%d.png", b);
			setObjectImage(aidice[i], buf);
			if ((i % 2) == 0) { aitempvalue += b; }
			else if ((i % 2) == 1) { aitempvalue *= b; aivalue += aitempvalue; aitempvalue = 0; }
		}
		game3wincheck();
	}
	else if (object == 130) {
		game4();
	}
	else if ((object == 131 || object == 132 || object == 133 || object == 134) && game4press==0) {
		game4press++;
		game4check[0] = object - 130;
		showObject(mini4check[object - 131]);
		game4wincheck();
	}
	else if (object == 165) {
		int temp;
		int unlucktemp[4] = { 0 };
		int miniwintemp[4] = { 0 };
		for (int i = 0;i < 4;i++) {
			unlucktemp[i] = unluck[i];
			miniwintemp[i] = minigamewin[i];
		}
		for (int i = 0; i < 4;i++) {
			for (int j = 0; j < 3 - i;j++) {
				if (unlucktemp[j] < unlucktemp[j + 1]) {
					temp = unlucktemp[j];
					unlucktemp[j] = unlucktemp[j + 1];
					unlucktemp[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3 - i; j++) {
				if (miniwintemp[j] < miniwintemp[j + 1]) {
					temp = miniwintemp[j];
					miniwintemp[j] = miniwintemp[j + 1];
					miniwintemp[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			if (unluck[i] == unlucktemp[0]) { star[i]++; showObject(awardstar[i]); }
			if (minigamewin[i] == miniwintemp[0]) { star[i]++; showObject(awardstar[i + 4]); }
		}
		int startemp[4] = { 0 };
		for (int i = 0;i < 4;i++) {
			startemp[i] = star[i];
		}
		for (int i = 0;i < 4;i++) {
			for (int j = 0; j < 3 - i;j++) {
				if (startemp[j] < startemp[j + 1]) {
					temp = startemp[j];
					startemp[j] = startemp[j + 1];
					startemp[j + 1] = temp;
				}
			}
		}
		if (star[0] == startemp[0]) { showMessage("플레이어(마리오)가 우승했습니다!"); }
		else if (star[1] == startemp[0]) { showMessage("루이지가 우승했습니다!"); }
		else if (star[2] == startemp[0]) { showMessage("굼바가 우승했습니다!"); }
		else if (star[3] == startemp[0]) { showMessage("엉금엉금이 우승했습니다!"); }
	}
	else {
	}
}
void timercallback(TimerID timer) {
	if (timer == timer1) {
		enterScene(gamescene[0]);
		movecheck = 0;
		char buf[500];
		sprintf(buf, "플레이어의 보유코인은 %d입니다.\n ai1의 보유코인은 %d입니다.\n ai2의 보유코인은 %d입니다.\n ai3의 보유코인은 %d입니다.", coin[0], coin[1], coin[2], coin[3]);
		showMessage(buf);
		setTimer(timer1, 10);
		locateObject(charr[0], gamescene[1], 600, 340);
		locateObject(charr[1], gamescene[1], 680, 340);
		locateObject(charr[2], gamescene[1], 600, 280);
		locateObject(charr[3], gamescene[1], 680, 280);
	}
	else if (timer == timer2) {
		if (mini2check[0] == 0) {
			int a = rand() % 3 + 1;
			int b = rand() % 4 + 1;
			mini2check[a] = b;
			showObject(squarec[b - 1]);
			int c, d;
			do {
				c = rand() % 3 + 1;
			} while (a == c);
			do {
				d = rand() % 4 + 1;
			} while (mini2check[0] == d || mini2check[a] == d);
			mini2check[c] = d;
			showObject(squarec[d - 1]);
			int e, f;
			do {
				e = rand() % 3 + 1;
			} while (a == e || c == e);
			do {
				f = rand() % 4 + 1;
			} while (mini2check[0] == f || mini2check[b] == f || mini2check[d] == f);
			mini2check[e] = f;
			showObject(squarec[f - 1]);
			mini2aiwincheck();
		}
		else {
			int a = rand() % 3 + 1; int b;
			do {
				b = rand() % 4 + 1;
			} while (mini2check[0] == b);
			mini2check[a] = b;
			showObject(squarec[b - 1]);
			int c, d;
			do {
				c = rand() % 3 + 1;
			} while (a == c);
			do {
				d = rand() % 4 + 1;
			} while (mini2check[0] == d || mini2check[a] == d);
			mini2check[c] = d;
			showObject(squarec[d - 1]);
			int e, f;
			do {
				e = rand() % 3 + 1;
			} while (a == e || c == e);
			do {
				f = rand() % 4 + 1;
			} while (mini2check[0] == f || mini2check[a] == f || mini2check[c] == f);
			mini2check[e] = f;
			showObject(squarec[f - 1]);
			mini2aiwincheck();
		}
	}
	else if (timer == timer3) {
		for (int i = 0; i < 4; i++) { mini2check[i] = 0; squareanswer[i] = 0; hideObject(squarec[i]); }
		for (int i = 0; i < 50; i++) {
			setObjectImage(square[i], "Images/K-028.png");
		}
		enterScene(gamescene[0]);
		movecheck = 0;
		char buf[500];
		sprintf(buf, "플레이어의 보유코인은 %d입니다.\n ai1의 보유코인은 %d입니다.\n ai2의 보유코인은 %d입니다.\n ai3의 보유코인은 %d입니다.", coin[0], coin[1], coin[2], coin[3]);
		showMessage(buf);
		setTimer(timer3, 10);

		startcheck = 0;

	}
	else if (timer == timer4) {
		for (int i = 0;i < 2;i++) {
			char buf[50];
			sprintf(buf, "Images/dice%d.png", rand() % 6 + 1);
			setObjectImage(playerdice[i], buf);
		}
		for (int i = 0; i < 6; i++) {
			char buf[50];
			sprintf(buf, "Images/dice%d.png", rand() % 3 + 1);
			setObjectImage(aidice[i], buf);
		}
		setTimer(timer4, 0.1f);
		startTimer(timer4);
	}
	else if (timer == timer5) {
		enterScene(gamescene[0]);
		movecheck = 0;
		char buf[500];
		sprintf(buf, "플레이어의 보유코인은 %d입니다.\n ai1의 보유코인은 %d입니다.\n ai2의 보유코인은 %d입니다.\n ai3의 보유코인은 %d입니다.", coin[0], coin[1], coin[2], coin[3]);
		showMessage(buf);
		setTimer(timer5, 10);
		playervalue = 0;
		aivalue = 0;
	}
	else if (timer == timer6) {
		for (int i = 0;i < game4correct;i++) {
			picolocate[i] -= picospeed[i];
			locateObject(pico[i], gamescene[4], picolocate[i], picolocatey[i]);
		}
		for (int i = 0;i < fakepicocorrect;i++) {
			fakepicolocate[i] -= picospeed[i];
			locateObject(fakepico[i], gamescene[4], fakepicolocate[i], picolocatey[i]);
		}
		setTimer(timer6, 0.1f);
		startTimer(timer6);
	}
	else if(timer==timer7){
	int a = rand() % 3 + 1; int b = 0;
	do {
		b = rand() % 4 + 1;
	} while (game4check[0] == b);
	game4check[a] = b;
	showObject(mini4check[b - 1]);
	int c, d;
	do {
		c = rand() % 3 + 1;
	} while (a == c);
	do {
		d = rand() % 4 + 1;
	} while (game4check[0] == d || game4check[a] == d);
	game4check[c] = d;
	showObject(mini4check[d - 1]);
	int e, f;
	do {
		e = rand() % 3 + 1;
	} while (a == e || c == e);
	do {
		f = rand() % 4 + 1;
	} while (game4check[0] == f || game4check[a] == f || game4check[c] == f);
	game4check[e] = f;
	showObject(mini4check[f - 1]);
	game4aiwincheck();
	setTimer(timer7, 15);
	stopTimer(timer6);
	stopTimer(timer7);
}
	else if (timer == timer8) {
	for (int i = 0;i < 30;i++) {
		picolocate[i] = 1300 + (i * 15);
		locateObject(pico[i], gamescene[4], picolocate[i], picolocatey[i]);
		picospeed[i] = 0;
	}
	for (int i = 0;i < 10;i++) {
		fakepicolocate[i] = 1350 + (i * 15);
		locateObject(fakepico[i], gamescene[4], fakepicolocate[i], fakepicolocatey[i]);
		fakepicospeed[i] = 0;
	}
	for (int i = 0;i < 4;i++) {
		game4check[i] = 0;
		hideObject(mini4check[i]);
	}
	enterScene(gamescene[0]);
	game4press = 0;
	char buf[500];
	sprintf(buf, "플레이어의 보유코인은 %d입니다.\n ai1의 보유코인은 %d입니다.\n ai2의 보유코인은 %d입니다.\n ai3의 보유코인은 %d입니다.", coin[0], coin[1], coin[2], coin[3]);
	showMessage(buf);
}
	else if (timer == timer9) {
	enterboardgame();
	setTimer(timer9, 5);
}
}
ObjectID makeobj(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}
int main() {
	srand((unsigned int)time(NULL));
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	gamescene[0] = createScene("보드게임", "Images/배경.png");
	timer1 = createTimer(10.0f);
	timer2 = createTimer(3.f);
	timer3 = createTimer(10.0f);
	timer4 = createTimer(0.1f);
	timer5 = createTimer(10.0f);
	timer6 = createTimer(0.1f);
	timer7 = createTimer(15.0f);
	timer8 = createTimer(10.0f);
	timer9 = createTimer(5.0f);
	for (int i = 1; i < 11; i++) {
		char buf[50];
		sprintf(buf, "미니게임%d", i-1);
		gamescene[i] = createScene(buf, "Images/배경4.png");
	}
	player[0] = makeobj("Images/char1.png", gamescene[0], 1080, 170, true);
	player[1] = makeobj("Images/char2.png", gamescene[0], 1130, 170, true);
	player[2] = makeobj("Images/char3.png", gamescene[0], 1080, 110, true);
	player[3] = makeobj("Images/char4.png", gamescene[0], 1130, 110, true);
	for (int i = 0; i < 4; i++) {
		scaleObject(player[i], 0.1f);
	}
	dice = makeobj("Images/dice.png", gamescene[0], 450, 285, true);
	inventory = makeobj("Images/inventorybutton.png", gamescene[0], 800, 300, true);
	for (int i = 0; i < 3; i++) {
		char buf[50];
		sprintf(buf, "Images/item%d.png", i + 1);
		item[i] = makeobj(buf, gamescene[0], 320 * (i + 1), 300, false);
		scaleObject(item[i], 0.66f);
	}
	backspace = makeobj("Images/leftarrow.png", gamescene[0], 160, 300, false);
	coincloud[0] = makeobj("Images/k-26.png", gamescene[1], 600, 76, true);
	coincloud[1] = makeobj("Images/k-27.png", gamescene[1], 600, 564, true);
	coincloud[2] = makeobj("Images/k-28.png", gamescene[1], 300, 320, true);
	coincloud[3] = makeobj("Images/k-28.png", gamescene[1], 900, 320, true);
	charr[0] = makeobj("Images/char1.png", gamescene[1], 600, 340, true);
	charr[1] = makeobj("Images/char2.png", gamescene[1], 680, 340, true);
	charr[2] = makeobj("Images/char3.png", gamescene[1], 600, 280, true);
	charr[3] = makeobj("Images/char4.png", gamescene[1], 680, 280, true);
	arrow[0] = makeobj("Images/leftarrow.png", gamescene[1], 0, 0, true);
	arrow[1] = makeobj("Images/uparrow.png", gamescene[1], 180, 0, true);
	arrow[2] = makeobj("Images/rightarrow.png", gamescene[1], 0, 180, true);
	arrow[3] = makeobj("Images/downarrow.png", gamescene[1], 180, 180, true);
	for (int i = 0; i < 4; i++) {
		scaleObject(charr[i], 0.1f);
	}
	for (int i = 0; i < 10; i++) {
		square[i] = makeobj("Images/K-028.png", gamescene[2], 100 + 100 * i, 620, true);
	}
	for (int i = 10; i < 20; i++) {
		square[i] = makeobj("Images/K-028.png", gamescene[2], 100 + 100 * (i-10), 520, true);
	}
	for (int i = 20; i < 30; i++) {
		square[i] = makeobj("Images/K-028.png", gamescene[2], 100 + 100 * (i-20), 420, true);
	}
	for (int i = 30; i < 40; i++) {
		square[i] = makeobj("Images/K-028.png", gamescene[2], 100 + 100 * (i-30), 320, true);
	}
	for (int i = 40; i < 50; i++) {
		square[i] = makeobj("Images/K-028.png", gamescene[2], 100 + 100 * (i-40), 220, true);
	}
	for (int i = 0; i < 4; i++) {
		char buf[50];
		sprintf(buf, "Images/k-0%d.png", 29 + i);
		squarecheck[i] = makeobj(buf, gamescene[2], 100 + 333 * i, 0, true);
	}
	ministart = makeobj("Images/start.png", gamescene[2], 1100, 150, true);
	for (int i = 0; i < 4; i++) {
		squarec[i] = makeobj("Images/check.png", gamescene[2], 100 + 333 * i, 0, false);
	}
	minichar[0] = makeobj("Images/char1.png", gamescene[3], 275, 200, true);
	minichar[1] = makeobj("Images/char2.png", gamescene[3], 800, 500, true);
	minichar[2] = makeobj("Images/char3.png", gamescene[3], 800, 300, true);
	minichar[3] = makeobj("Images/char4.png", gamescene[3], 800, 50, true);
	for (int i = 0; i < 4; i++) {
		scaleObject(minichar[i], 0.2f);
	}
	playerdice[0] = makeobj("Images/dice1.png", gamescene[3], 150, 400, true);
	scaleObject(playerdice[0], 0.5f);
	playerdice[1] = makeobj("Images/dice1.png", gamescene[3], 450, 400, true);
	scaleObject(playerdice[1], 0.5f);
	for (int i = 0; i < 6; i++) {
		aidice[i] = makeobj("Images/dice1.png", gamescene[3], 900+300*(i%2), 600-250*(i/2), true);
		scaleObject(aidice[i], 0.5f);
	}
	mini3start = makeobj("Images/start.png", gamescene[3], 100, 100, true);
	mini3end = makeobj("Images/end.png", gamescene[3], 200, 100, true);
	for (int i = 0; i < 4; i++) {
		if (i == 0) { multiple[i] = makeobj("Images/multiple.png", gamescene[3], 300, 400, true); }
		else { multiple[i] = makeobj("Images/multiple.png", gamescene[3], 1025, 850 - (250 * i), true); }
	}
	for (int i = 0;i < 30;i++) {
		picolocate[i] = 1300 + (i * 50);
		picolocatey[i] = 250 + (rand() % 250);
		pico[i] = makeobj("Images/game4.png", gamescene[4], picolocate[i], picolocatey[i], true);
	}
	
	game4start = makeobj("Images/start.png", gamescene[4], 100, 100, true);
	for (int i = 0; i < 4; i++) {
		char buff[50];
		sprintf(buff, "Images/%d.png", 27 + i);
		game4answer[i] = makeobj(buff, gamescene[4], 100 + (333 * i), 0, true);
	}
	for (int i = 0; i < 4;i++) {
		mini4check[i] = makeobj("Images/check.png", gamescene[4], 100 + (333 * i), 0, false);
	}
	for (int i = 0;i < 10;i++) {
		fakepicolocate[i] = 1350 + (i * 50);
		fakepicolocatey[i] = 250 + (rand() % 250);
		fakepico[i] = makeobj("Images/fakepico.png", gamescene[4], fakepicolocate[i], picolocatey[i], true);
	}
	charicon[0] = makeobj("Images/char1.png", gamescene[0], 0, 550, true);
	charicon[1] = makeobj("Images/char2.png", gamescene[0], 1200, 550, true);
	charicon[2] = makeobj("Images/char3.png", gamescene[0], 0, 0, true);
	charicon[3] = makeobj("Images/char4.png", gamescene[0], 1200, 0, true);
	for (int i = 0; i < 4; i++) {
		scaleObject(charicon[i], 0.15f);
	}
	for (int i = 0;i < 12;i++) {
		if (i < 3) { mainstar[i] = makeobj("Images/star.png", gamescene[0], 100 + (i * 150), 600, false); }
		else if (i==3||i==4||i==5) { mainstar[i] = makeobj("Images/star.png", gamescene[0], 1100 - ((i - 3) * 150), 600, false); }
		else if (i==6||i==7||i==8) { mainstar[i] = makeobj("Images/star.png", gamescene[0], 100 + ((i - 6) * 150), 0, false); }
		else if (i==9||i==10||i==11) { mainstar[i] = makeobj("Images/star.png", gamescene[0], 1100 - ((i - 9) * 150), 0, false); }
	}
	awardstart = makeobj("Images/start.png", gamescene[10], 640, 320, true);
	for (int i = 0;i < 4;i++) {
		char buf[50];
		sprintf(buf, "Images/char%d.png", i + 1);
		awardchar[i] = makeobj(buf, gamescene[10], 150 + 300 * i, 250, true);
		awardstar[i] = makeobj("Images/star.png", gamescene[10], 150 + 300 * i, 400, false);
		awardstar[i + 4] = makeobj("Images/star.png", gamescene[10], 150 + 300 * i, 600, false);
		scaleObject(awardchar[i], 0.1f);
	}
	showMessage("결승점에 도달했을 때 코인이 30개 이상 있다면 스타를 얻습니다.\n이 스타가 가장 많은 플레이어가 승리합니다.\n붉은 칸은 코인 3개 감소. 버섯 칸은 랜덤한 아이템.\n 물음표 칸은 전 코인 감소. 느낌표 칸은 모든 아이템 하나씩.\n 나머지 칸은 코인 3개 획득입니다.");
	setMouseCallback(mousecallback);
	setTimerCallback(timercallback);
	startGame(gamescene[0]);
}