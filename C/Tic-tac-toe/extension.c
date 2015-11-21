#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//-----------------------------------------------------------------------------
//                                BATTLE SYSTEM
//-----------------------------------------------------------------------------


int HP = 15;

int Ghoul() {
  int choice;
  int ghoulhp = 18;
  printf("You have been attacked by a Ghoul! quick choose your weapon and fight back!");
  printf("Choose a weapon:\n");
  printf(" [1] Silver Sowrd\n");
  printf(" [2] Steel Sword\n");
  scanf("%d",&choice);

//Silver sword

  if (choice == 1) {
    while (ghoulhp > 0) {
      printf("The Ghoul is about to attack!\n");
      printf("press [Enter] to attempt to dodge the attack\n");
      char myChar155 = 0;
      while (myChar155 != '\n' && myChar155  != '\r') {
          myChar155 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 6;
      printf("The Ghoul has been hit!\n");
    if (ghoulhp == 6) {
      printf("The Ghoul seems weak! One more attack and it will die!\n");

    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Ghoul! well done Witcher.\n");
  }

//Steel sword

  if (choice == 2) {
  printf("Foolish Witcher! you have chosen the wrong type of sword.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Ghoul is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 3;
      printf("The Ghoul has been hit!\n");
    if (ghoulhp == 1) {
      printf("The Ghoul seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Ghoul! well done Witcher.\n");
  }

//Fists

  else if (choice != 1 && choice != 2) {
    printf("THAT IS NOT A CHOICE WITHCER! You will have to use fists\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Ghoul is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 1;
      printf("The Ghoul has been hit!\n");
    if (ghoulhp == 1) {
      printf("The Ghoul seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Ghoul! well done Witcher.\n");
  }
  printf("Press [Enter] to continue.\n");
  char myChar00 = 0;
      while (myChar00 != '\n' && myChar00  != '\r') {
          myChar00 = getchar();
      }
}

//Bandits


int Bandit(){
  int choice;
  int ghoulhp = 18;
  printf("You have been attacked by a Bandit! quick choose your weapon and fight back!");
  printf("Choose a weapon:\n");
  printf(" [1] Silver Sowrd\n");
  printf(" [2] Steel Sword\n");
  scanf("%d",&choice);

//Silver sword

  if (choice == 1) {
    printf("Foolish Witcher! you have chosen the wrong type of sword.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Bandit is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 3;
      printf("The Bandit has been hit!\n");
    if (ghoulhp == 3) {
      printf("The Bandit seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Bandit! well done Wicther.\n");
  }

//Steel sword

  if (choice == 2) {
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Bandit is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 6;
      printf("The Bandit has been hit!\n");
    if (ghoulhp == 6) {
      printf("The Bandit seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Bandit! well done Witcher.\n");
  }

//Fists

  else  if (choice != 1 && choice != 2){
    printf("THAT IS NOT A CHOICE WITHCER! You will have to use fists.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Bandit is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
              getchar();
      ghoulhp = ghoulhp - 1;
      printf("The Bandit has been hit!\n");
    if (ghoulhp == 1) {
      printf("The Bandit seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Bandit! well done Witcher.\n");
  }
  printf("Press [Enter] to continue.\n");
  char myChar00 = 0;
      while (myChar00 != '\n' && myChar00  != '\r') {
          myChar00 = getchar();
      }
}

//Drowners

int Drowner(){
  int choice;
  int ghoulhp = 27;
  printf("You have been attacked by a Drowner! quick choose your weapon and fight back!");
  printf("Choose a weapon:\n");
  printf(" [1] Silver Sowrd\n");
  printf(" [2] Steel Sword\n");
  scanf("%d",&choice);

//Silver sword

  if (choice == 1) {
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Drowner is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 2;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 6;
      printf("The Drowner has been hit!\n");
    if (ghoulhp == 6) {
      printf("The Drowner seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died. lol.\n");
      return 0;
    }
    }
    printf("You have defeated the Drowner! well done Witcher.\n");
  }

//Steel sword

  if (choice == 2) {
  printf("Foolish Witcher! you have chosen the wrong type of sword.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Drowner is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 2;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 3;
      printf("The Drowner has been hit!\n");
    if (ghoulhp == 3) {
      printf("The Drowner seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Drowner! well done Witcher.\n");
  }

//Fists

  else if (choice != 1 && choice != 2) {
  //  printf("THAT IS NOT A CHOICE WITHCER! You will have to use fists.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Drowner is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 2;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 1;
      printf("The Drowner has been hit!\n");
    if (ghoulhp == 1) {
      printf("The Drowner seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Drowner! well done Witcher.\n");
//    printf("Drowners are difficult to beat even with swords... I bet you have cheated...\n");
  }
  printf("Press [Enter] to continue.\n");
  char myChar00 = 0;
      while (myChar00 != '\n' && myChar00  != '\r') {
          myChar00 = getchar();
      }
}

int WildDogs() {
  int choice;
  int ghoulhp = 6;
  printf("You have been attacked by a Wild Dog! quick choose your weapon and fight back!");
  printf("Choose a weapon:\n");
  printf(" [1] Silver Sowrd\n");
  printf(" [2] Steel Sword\n");
  scanf("%d",&choice);

//Silver sword

  if (choice == 1) {
    printf("Foolish Witcher! you have chosen the wrong type of sword.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Wild Dog is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 2;
      printf("The Wild Dog has been hit!\n");
    if (ghoulhp == 3) {
      printf("The Wild Dog seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Wild Dog! well done Wicther.\n");
  }

//Steel sword

  if (choice == 2) {
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Wild Dog is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 3;
      printf("The Wild Dog has been hit!\n");
    if (ghoulhp == 3) {
      printf("The Wild Dog seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died\n");
      return 0;
    }
    }
    printf("You have defeated the Wild Dog! well done Witcher.\n");
  }

//Fists

  else if (choice != 1 && choice != 2){
    printf("THAT IS NOT A CHOICE WITHCER! You will have to use fists.\n");
    while (ghoulhp > 0) {
      char myChar6 = 0;
      while (myChar6 != '\n' && myChar6  != '\r') {
          myChar6 = getchar();}
      printf("The Wild Dog is about to attack!\n");
      printf("press [Enter] to attempt  to dodge the attack\n");
      char myChar1 = 0;
      while (myChar1 != '\n' && myChar1  != '\r') {
          myChar1 = getchar();}
      int r = rand () % 3;
    if (r == 0) {
      HP--;
      printf("You have been hit! Your HP is %d/15\n", HP);
    }
    else if (r != 0) {
      printf("You have dodged the attack!\n");
    }
      printf("press [Enter] to attack!\n");
      char myChar = 0;
          while (myChar != '\n' && myChar  != '\r') {
              myChar = getchar();}
      ghoulhp = ghoulhp - 1;
      printf("The Wild Dog has been hit!\n");
    if (ghoulhp == 1) {
      printf("The Wild Dog seems weak! One more attack and it will die!\n");
    }
    if (HP == 0) {
      printf("You have died... to a dog... pfffttt...\n");
      return 0;
    }
    }
    printf("You have defeated the Wild Dog! well done Witcher.\n");
  }
  printf("Press [Enter] to continue.\n");
  char myChar00 = 0;
      while (myChar00 != '\n' && myChar00  != '\r') {
          myChar00 = getchar();
      }
}

int Thug(){
  int ghoulhp = 3;
  while (ghoulhp > 0) {
    printf("The Thug is about to attack!\n");
    printf("press [Enter] to attempt  to dodge the attack\n");
    char myChar1 = 0;
    while (myChar1 != '\n' && myChar1  != '\r') {
        myChar1 = getchar();}
    int r = rand () % 3;
  if (r == 0) {
    HP--;
    printf("You have been hit! Your HP is %d/15\n", HP);
  }
  else if (r != 0) {
    printf("You have dodged the attack!\n");
  }
    printf("press [Enter] to attack!\n");
    char myChar = 0;
        while (myChar != '\n' && myChar  != '\r') {
            myChar = getchar();}
    ghoulhp = ghoulhp - 1;
    printf("The Thug has been hit!\n");
  if (ghoulhp == 1) {
    printf("The Thug seems weak! One more attack and it will die!\n");
  }
  if (HP == 0) {
    printf("You have died... to a very easy fight...\n");
    return 0;
  }
  }
  printf("You have defeated the Thug! well done Witcher.\n");
  printf("Press [Enter] to continue.\n");
  char myChar00 = 0;
      while (myChar00 != '\n' && myChar00  != '\r') {
          myChar00 = getchar();
      }
}



//-----------------------------------------------------------------------------
//                                STORY
//-----------------------------------------------------------------------------

int main (int argc, char **argv) {
int choice;

//----------
//Welcome Screen
//----------

  printf("Welcome to Witcher 3 text based version!!\n\n");
  printf("You will be playing as the protagonist of the orignal game Geralt of Rivia.\n");
  printf("Geralt is a witcher. \"What is a witcher\" you might ask.");
  printf("Witcher are monster hunters that went through mutation where they developed\n");
  printf("strenght and supernatural senses known as witcher senses\n");
  printf("The story takes place in a medieval fantasy world, where Geralt is searching\n");
  printf("for a sorceress named Yennefer.\n\n");
  printf("It is important to know that witchers including Geralt carry two swords.\n");
  printf("One is made of Steel, which is used to kill animals and humans.\n");
  printf("The other is made of Silver, which is used to kill monsters\n");
  printf("before every fight you get to chose which sword should you use\n");
  printf("if you choose the wrong sword the fight might be difficult.\n");
  printf("You get the chance to doge the oppents attack as well.\n");
  printf("Now shall we begin? Press [1] if want to start playing\n");

  scanf("%d", &choice);

  if (choice != 1) {
    while(choice != 1){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice);}
  }

  //----------
  //Story Starts
  //----------

  if (choice == 1) {
    printf("The story begins where Geralt and Vesemir some where near a village\n");
    printf("called White Ochard.\n");
    printf("Vesemir is an old witcher who is a father figure to Geralt.\n\n");
    printf("Geralt suddenly wakes up from a nightmare.\n");
    printf("Vesemir: You all right?\n");
    printf("Geralt: Mhm. had a nightmare...\n");
    printf("Vesemir: about?\n");
    printf("Geralt: Take for ever to exlpain.\n");
    printf("Vesemir: Dawn's some way off. We've got time\n\n");

    printf("[1] I dreamt of...\n");
    printf("[2] Really rather not talk about it.\n");
  }

//I dreamt of...

int choice2; scanf("%d",&choice2);

if (choice2 != 1 && choice2 != 2) {
  while(choice2 != 1 && choice2 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice2);}
}

if (choice2 == 1) {
  printf("Geralt: Started in my room in our home... at Kaer Morhen. I was relaxing in the tub.\n");
  printf("Geralt: In the dream, I went and found Ciri. Then we trained.\n");
  printf("   Note:: that Ciri is Geralt's daughter who he has adopted long time ago\n");
  printf("Vesemir: Those were the days... Hm, little She-devil.\n");
  printf("Vesemir: I've trianed kids who were faster, stronger - but none had her character.\n");
  printf("Vesemir: Didn't end well, did it? Your dream.\n");
  printf("Geralt: No. The Wild Hunt appeared, attacked Ciri... I couldn't move.\n");
  printf("Geralt: Stood there like a stump\n");
  printf("Vesemir: It was just a dream.\n\n");
  }

  //Don't want to talk about it

if (choice2 != 1 && choice2 != 2) {
  while(choice2 != 1 && choice2 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice2);}
}

else if (choice2 == 2) {
  printf("Gerlat: I rather not to talk about it.\n");
  printf("Vesemir: Ok. let's wait till dawn.\n\n");
}
printf("Press [Enter] to continue\n");
char myChar4 = 0;
  while (myChar4 != '\n' && myChar4  != '\r') {
      myChar4 = getchar();
  }

//Conversation

getchar();
printf("Geralt: Be dawning soon. Time to go.\n");
printf("Vesemir: Wait. Show me the letter from Yennefer, might've overlooked some hint in there.\n");
printf("Gerlat: Didn't overlook anything. We were meant to meet in Willoughby.\n");
printf("Gerlat: that's what she wrote.\n");
printf("Geralt: Meanwhile one army or another burned the village to the ground.\n");
printf("Gerlat: all we can do is follow her trail.\n");
printf("Vesemir: Stop talking for a minute and give me the letter.\n");
printf("Geralt hands the letter to Vesemir.\n");
printf("Vesemir:Well, how about that!. It does smell of lilac and gooseberries.\n");
printf("Geralt: You were gonna read it, not sniff it.\n");
printf("Vesemir: \"We must meet. Soon\"... \"Willoughby, near Vizima\"...\n");
printf("Vesemir: Hm, nothing else to guide us there\n");
printf("Vesemir: What's this postscript? \"I still have the unicorn.\" \n");
printf("Geralt: That's private... Very private...\n");
printf("Vesemir: A-ha... I understand. Least I think I do. Maybe not entirely...\n");
printf("Vesemir: but... perhaps that's for the best.\n");
printf("Geralt: Back on topic. How's it look - how far behind Yennefer are we?.");
printf("Two, three days... Trail's fresh. But it looks like it leads towards the main road. Could be muddled there.\n");
printf("Press [Enter] to continue\n");
char myChar3 = 0;
    while (myChar3 != '\n' && myChar3  != '\r') {
        myChar3 = getchar();
    }
printf("Vesemir: Wait! you hear that?.\n");
printf("Geralt: I hear it, I smell it. Ghouls.\n\n");
printf("Press [Enter] to fight the Ghoul.\n");
char myChar7 = 0;
    while (myChar7 != '\n' && myChar7  != '\r') {
        myChar7 = getchar();
    }
Ghoul();

//After fight

printf("Vesemir: Ofcourse. When armies pass, necrophages fellow.\n");
printf("Let's go before any show up.\n\n");
printf("Geralt and Vesemir got on their horses and now they are heading to White Ochard.\n");
printf("Geralt: Ever told you about this sorcerer I knew?\n");
printf("Geralt: Couldn't stop talking about how useful they are as creatures(Ghoul).");
printf("Vesemir: Because you can brew potions from their blood?\n");
printf("Hen, no. Because by eating rotting corpses they prevent epidemics.\n");
printf("Vesemir: Hmph. Did he know they eat the living as well?.\n");
printf("Geralt: No. Really upset him, too... His theory collapsed.\n");
printf("Press [Enter] to go White Ochard.\n");
char myChar8 = 0;
    while (myChar8 != '\n' && myChar8  != '\r') {
        myChar8 = getchar();
    }

    //----------
    //arriving at White Orchard
    //----------

printf("Upon arriving White Ochard, Geralt and Vesemir encountered a merchant who is under attack by Griffin.\n");
printf("Merchant: Help! Help me.\n");
printf("The merchant is hiding under the horse carriage, while the Griffin devours the horse.\n");
printf("Geralt rushed forward and slashed the Griffin, then the Griffin flew off and attacked Vesemir\n");
printf("As Vesemir, got his arm injured from the Griffin's attack.\n");
printf("The Griffin picked up the horse and flew off. \n\n");

printf("Press [Enter] to to continue\n");
char myChar9 = 0;
    while (myChar9 != '\n' && myChar9  != '\r') {
        myChar9 = getchar();
}
printf("Merchant: Ha-has it gone?.\n");
printf("Geralt: Yeah. Come out.\n");
printf("Merchant: Gods, that was close! I was sure I'd end up like my mare.\n");
printf("Vesemir: Provided you got lucky.\n");
printf("Your horse died quickly. But Griffins like to toy with their prey. Eait it, alive, piece by piece.\n");
printf("Merchant: Ahh-ha.\n");
printf("Merchant: You'd... like a reward I suppose?. \n\n");
printf("[1] You don't owe us a thing.\n");
printf("[2] We could use a few coins.\n");

int choice3;
scanf("%d",&choice3);

if (choice3 != 1 && choice3 != 2) {
  while(choice3 != 1 && choice3 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice3);}
}

//Nice

if (choice3 == 1) {
  printf("Geralt: You don't owe us anything. You were in need, we helped.\n");
  printf("Merchant: And they call witchers heartless. Say they won't lift a finger without a pay.\n");
  printf("Geralt: They also say mice are born of rotting straw.\n");
  printf("Geralt: Back to track?.\n");
  printf("Vesemir: Like I said - lead to the main road and ends there. Muddled.\n");
  printf("Merchant: You seek someone? \n\n");
  printf("[1] Yeah - a woman.\n");
  printf("[2] Why do you care?\n");

int choice4;
scanf("%d",&choice4);

if (choice4 != 1 && choice4 != 2) {
  while(choice4 != 1 && choice4 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice4);}
}

if (choice4 == 1){
  printf("Geralt: Yes, a woman, medium height, black hair. Seen anyone like that?\n");
  printf("Merchant: No. But... There's an inn here in White Orchard. Sole one around.\n");
  printf("Merchant: Gets its share of travelers, perhaps you'll learn something there.\n");
  printf("Merchant: Besides, the innkeep's my cousin. Tell her Bram sent you, she'll treat you like family.\n");
  printf("Geralt: Not a bad idea. Especially since that wound needs cleaning.\n");
  printf("Vesemir: Bah, beast barely grazed me. But sure... could use a good rye.\n");
  printf("Vesemir: Nice and cool, you know, striaght from a celler?.\n");
  printf("Geralt: Let's go.\n");
}
else  if (choice4 == 2) {
    printf("Geralt: Why would you care?\n");
    printf("Merchant: Well... if you are looking for somebody. There's an inn here in White Orchard.\n");
    printf("Merchant: Sole one around. Gets its share of travelers, perhaps you'll learn something there.\n");
    printf("Merchant: Besides, the innkeep's my cousin. Tell her Bram sent you, she'll treat you like family.\n");
    printf("Geralt: Not a bad idea. Especially since that wound needs cleaning.\n");
    printf("Vesemir: Bah, beast barely grazed me. But sure... could use a good rye.\n");
    printf("Vesemir: Nice and cool, you know, striaght from a celler?.\n");
    printf("Geralt: Let's go.\n");
  }
}

//Rude

else if (choice3 == 2) {
  printf("Geralt: Little coin does hurt.\n");
  printf("The merchant gives Geralt bit of coins.\n");
  printf("Geralt: Back to track?.\n");
  printf("Vesemir: Like I said - lead to the main road and ends there. Muddled.\n");
  printf("Merchant: You seek someone? \n\n");
  printf("[1] Yeah - a woman.\n");
  printf("[2] Why do you care?\n");
  int choice4;
  scanf("%d",&choice4);

  if (choice4 != 1 && choice4 != 2) {
    while(choice4 != 1 && choice4 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice4);}
}

  if (choice4 == 1){
    printf("Geralt: Yes, a woman, medium height, black hair. Seen anyone like that?\n");
    printf("Merchant: No. But... There's an inn here in White Orchard. Sole one around.\n");
    printf("Merchant: Gets its share of travelers, perhaps you'll learn something there.\n");
    printf("Geralt: Not a bad idea. Especially since that wound needs cleaning.\n");
    printf("Vesemir: Bah, beast barely grazed me. But sure... could use a good rye.\n");
    printf("Vesemir: Nice and cool, you know, striaght from a celler?.\n");
    printf("Geralt: Let's go.\n");
  }
  else if (choice4 == 2) {
      printf("Geralt: Why would you care?\n");
      printf("Merchant: Well... if you are looking for somebody. There's an inn here in White Orchard.\n");
      printf("Merchant: Sole one around. Gets its share of travelers, perhaps you'll learn something there.\n");
      printf("Geralt: Not a bad idea. Especially since that wound needs cleaning.\n");
      printf("Vesemir: Bah, beast barely grazed me. But sure... could use a good rye.\n");
      printf("Vesemir: Nice and cool, you know, striaght from a celler?.\n");
      printf("Geralt: Let's go.\n");
    }
}
printf("Press [Enter] to continue\n");
char myChar11 = 0;
    while (myChar11 != '\n' && myChar11  != '\r') {
        myChar11 = getchar();}
        getchar();

        //----------
        //The Inn
        //----------

printf("Geralt and Vesemir are on their mare heading to the Inn.\n");
printf("Geralt: So... a Griffin this closr to the village? Strange.\n");
printf("Vesemir: My thoughts exactly, In a forest or the mountains sure, but here? and near the main road?\n");
printf("Gerlat: Maybe the war. Corpses everywhere, the stench of blood, burnt flesh... drives monster crazy.\n");
printf("Vesemir: We need to watch ourselves in White Orchard. And we should leave as soon as we learn anything.\n\n");

printf("Press [Enter] to enter the Inn\n");
char myChar12 = 0;
    while (myChar12 != '\n' && myChar12  != '\r') {
        myChar12 = getchar();}

printf("Vesemir and Geralt have arrived at the keep. They have caught everyone's attention in the Inn.\n");
printf("Person #1: Wha? Witchers...?\n");
printf("As Geralt walks by group of people drinking.\n");
printf("Person #2: I'll not drink with weevil freaks.\n");
printf("Geralt stop for breif moment, but he decided to ignore them. \n");
printf("Innkeep: Beg your pardon for those thugs.\n");
printf("Vesemir: No need. We're used to it.\n");
printf("Innkeep: Folk're jumpy. Armies just passed through, now a Griffin's prowlin' about...\n");
printf("Geralt: Mhm. Already had the pleasure.\n");

//This happens only if you didn't take the money from the guy that was saved.

if (choice3 == 1){
  printf("Geralt: Ran into your kinsman, Bram.\n");
  printf("Innkeep: Bram? How is he?\n");
  printf("Vesemir: Alive. Sends his regards.\n");
  printf("Innkeep: Master witchers... food and drink on the house. What can I get you?.\n");
}
printf("Press [Enter] to ask about the inkeep about Yennefer.\n");
char myChar13 = 0;
    while (myChar13 != '\n' && myChar13  != '\r') {
        myChar13 = getchar();}

printf("Geralt: Looking for a woman. Raven-haired, violet eyes. Dresses in black and white.\n");
printf("Geralt: Riding in from Willoughby. And, uh, strange as it sounds...\n");
printf("Geralt: Lilac and gooseberries, might've smelled that\n");
printf("Innkeep: I've not seen nor smelt such a lady. Believe I'd remember.\n");
printf("Vesemir: Yeah. Especially hard to forget this one.\n");
printf("Innkeep: Plenty of travelers about, though, folk from all over.\n");
printf("Innkeep: Might be worth your while to ask after her.\n");
printf("Geralt: Thanks. For everything.\n");

printf("Press [Enter] to continue.\n");
char myChar14 = 0;
    while (myChar14 != '\n' && myChar14  != '\r') {
        myChar14 = getchar();}

printf("Vesemir went and sat in a table by himself as he bandaging his wound from the griffin.\n");
printf("Geralt: Help you bandage that up?\n");
printf("Vesemir: Please. I'm not decrepit yet.\n");
printf("Geralt: Then I will ask about Yennefer.\n");
printf("Vesemir: Mhm. Just remember - we'd rather not draw any attention\n\n");

printf("[1] Speak to group of travelers #1\n");
printf("[2] Speak to group of travelers #2\n");
printf("[3] Speak to a man sitting by himself\n");

//9 different possiblites.

int choice5;
scanf("%d",&choice5);

if (choice5 != 1 && choice5 != 2 && choice5 != 3) {
  while(choice5 != 1 && choice5 != 2 && choice5 != 3){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice5);}
}


if (choice5 == 1){
  printf("Geralt: I'm looking for someone.\n");
  printf("Person #1: And we seek some peace and quiet.\n");
  printf("Person #2: Outta my face, freak. 'fore your breath sours my beer.\n\n");

  printf("[1] Speak to group of travelers #2\n");
  printf("[2] Speak to a man sitting by himself\n");

int choice6;
scanf("%d",&choice6);

if (choice6 != 1 && choice6 != 2) {
  while(choice6 != 1 && choice6 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice6);}
}

if (choice6 == 1) {
  printf("Geralt: Gotta a minute?\n");
  printf("Person #1: Why not. Alder Geert, assiant professer in contemporary history at Oxenfurt Academy.\n");
  printf("Gerlat: Geralt of Rivia. Witcher with tenure.\n");
  printf("Geralt: I'm looking for a woman - long hair, dressed in black and white. seen anyone like that?\n");
  printf("Alder: No, I haven't seen anyone like that. \n\n");
  printf("There is one person left to speak with. press [Enter] to continue.\n");
  char myChar15 = 0;
      while (myChar15 != '\n' && myChar15  != '\r') {
          myChar15 = getchar();}
          getchar();
printf("Geralt: Looking for a woman.\n");
printf("Travler #1: Ahh, like everyone.\n");
printf("Geralt: Not like everyon, and not just any woman.\n");
printf("Geralt: Mine smells of lilca and gooseberries, dresses in black and white.\n");
printf("Travler shouts for an order \"Tow schnappses!\".\n");
printf("Travler: Hah. It'll lift your spirits.\n\n");

printf("[1] Fine, I'll have a drink.\n");
printf("[2] Let's get to the point.\n");

int choice7;
scanf("%d",&choice7);

if (choice7 != 1 && choice7 != 2) {
  while(choice7 != 1 && choice7 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice7);}
}

if (choice7 == 1) {
  printf("Geralt: Little drink won't hurt I guess.\n");
  printf("Travler: So... Yennefer of Vengerberg?\n");
  printf("Gerlat: Never mentioned her name.\n");
  printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

  printf("[1] How do you know Yennefer?\n");
  printf("[2] Who might you be?\n"); }

if (choice7 == 2) {
  printf("Geralt: Finding her - that'll lift my spirits.\n");
  printf("Travler: You look haggard. It's just a few drops to improve your mood.\n");
  printf("A little schnappsie's never hurt a soul.\n");
  printf("Geralt: Can we cut to the chase? You seen her or not?\n");
  printf("Travler: Yennefer of Vengerberg?\n");
  printf("Gerlat: Never mentioned her name.\n");
  printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

  printf("[1] How do you know Yennefer?\n");
  printf("[2] Who might you be?\n"); }

int choice8;
scanf("%d",&choice8);

if (choice8 != 1 && choice8 != 2) {
  while(choice8 != 1 && choice8 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice8);}
}

  if (choice8 == 1) {
    printf("Geralt: So how do you know Yennefer?\n");
    printf("Travler: What a question. Master Dandelion's ballads, of course.");
    printf("Travler: They only way a humbke merchant might hope to rub up against greatness.\n");
    printf("Travler: Unless, that is he's as lucky as I am.\n");
    printf("Geralt: And runs into a very patient witcher?\n");
    printf("Travler: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

    printf("press [Enter] to ask the traveler who he is. \n");
    char myChar15 = 0;
        while (myChar15 != '\n' && myChar15  != '\r') {
            myChar15 = getchar();}
            getchar();

    printf("Geralt: What do you do? Who are you?\n");
    printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
    printf("Geralt: Vagrant - is that a profession now?\n");
    printf("Gaunter: Ah, once a merchant of mirrors.\n");
    printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

    printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
    char myChar16 = 0;
        while (myChar16 != '\n' && myChar16  != '\r') {
            myChar16 = getchar();}

  }

  else if (choice8 == 2){
    printf("Geralt: What do you do? Who are you?\n");
    printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
    printf("Geralt: Vagrant - is that a profession now?\n");
    printf("Gaunter: Ah, once a merchant of mirrors.\n");
    printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

    printf("press [Enter] to ask the Gaunter How he does know Yennefer.\n.");
    char myChar15 = 0;
        while (myChar15 != '\n' && myChar15  != '\r') {
            myChar15 = getchar();}
            getchar();

            printf("Geralt: So how do you know Yennefer?\n");
            printf("Gaunter: What a question. Master Dandelion's ballads, of course.");
            printf("Gaunter: They only way a humbke merchant might hope to rub up against greatness.\n");
            printf("Gaunter: Unless, that is he's as lucky as I am.\n");
            printf("Geralt: And runs into a very patient witcher?\n");
            printf("Gaunter: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

            printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
            char myChar16 = 0;
                while (myChar16 != '\n' && myChar16  != '\r') {
                    myChar16 = getchar();}

  }


}
if (choice6 == 2) {
  printf("Geralt: Looking for a woman.\n");
  printf("Travler #1: Ahh, like everyone.\n");
  printf("Geralt: Not like everyon, and not just any woman.\n");
  printf("Geralt: Mine smells of lilca and gooseberries, dresses in black and white.\n");
  printf("Travler shouts for an order \"Tow schnappses!\".\n");
  printf("Travler: Hah. It'll lift your spirits.\n\n");

  printf("[1] Fine, I'll have a drink.\n");
  printf("[2] Let's get to the point.\n");

  int choice7;
  scanf("%d",&choice7);

  if (choice7 != 1 && choice7 != 2) {
    while(choice7 != 1 && choice7 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice7);}
}

  if (choice7 == 1) {
    printf("Geralt: Little drink won't hurt I guess.\n");
    printf("Travler: So... Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n"); }


  if (choice7 == 2) {
    printf("Geralt: Finding her - that'll lift my spirits.\n");
    printf("Travler: You look haggard. It's just a few drops to improve your mood.\n");
    printf("A little schnappsie's never hurt a soul.\n");
    printf("Geralt: Can we cut to the chase? You seen her or not?\n");
    printf("Travler: Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n");}

  int choice8;
  scanf("%d",&choice8);

  if (choice8 != 1 && choice8 != 2) {
    while(choice8 != 1 && choice8 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice8);}
}

    if (choice8 == 1) {
      printf("Geralt: So how do you know Yennefer?\n");
      printf("Travler: What a question. Master Dandelion's ballads, of course.");
      printf("Travler: They only way a humbke merchant might hope to rub up against greatness.\n");
      printf("Travler: Unless, that is he's as lucky as I am.\n");
      printf("Geralt: And runs into a very patient witcher?\n");
      printf("Travler: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

      printf("press [Enter] to ask the traveler who he is. \n");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}

      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
      char myChar16 = 0;
          while (myChar16 != '\n' && myChar16  != '\r') {
              myChar16 = getchar();}

    }

    if (choice8 == 2){
      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask the Gaunter How he does know Yennefer.\n.");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}

              printf("Geralt: So how do you know Yennefer?\n");
              printf("Gaunter: What a question. Master Dandelion's ballads, of course.");
              printf("Gaunter: They only way a humbke merchant might hope to rub up against greatness.\n");
              printf("Gaunter: Unless, that is he's as lucky as I am.\n");
              printf("Geralt: And runs into a very patient witcher?\n");
              printf("Gaunter: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

              printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
              char myChar16 = 0;
                  while (myChar16 != '\n' && myChar16  != '\r') {
                      myChar16 = getchar();}

    }



}
} //choice5 == 1 ends here

if (choice5 == 2){
  printf("Geralt: Gotta a minute?\n");
  printf("Person #1: Why not. Alder Geert, assiant professer in contemporary history at Oxenfurt Academy.\n");
  printf("Gerlat: Geralt of Rivia. Witcher with tenure.\n");
  printf("Geralt: I'm looking for a woman - long hair, dressed in black and white. seen anyone like that?\n");
  printf("Alder: No, I haven't seen anyone like that. \n\n");

  printf("[1] Speak to group of travelers #1\n");
  printf("[2] Speak to a man sitting by himself\n");

int choice6;
scanf("%d",&choice6);

if (choice6 != 1 && choice6 != 2) {
  while(choice6 != 1 && choice6 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice6);}
}

if (choice6 == 1) {
  printf("Geralt: I'm looking for someone.\n");
  printf("Person #1: And we seek some peace and quiet.\n");
  printf("Person #2: Outta my face, freak. 'fore your breath sours my beer.\n\n");

  printf("There is one person left to speak with. press [Enter] to continue.\n");
  char myChar15 = 0;
      while (myChar15 != '\n' && myChar15  != '\r') {
          myChar15 = getchar();}

printf("Geralt: Looking for a woman.\n");
printf("Travler #1: Ahh, like everyone.\n");
printf("Geralt: Not like everyon, and not just any woman.\n");
printf("Geralt: Mine smells of lilca and gooseberries, dresses in black and white.\n");
printf("Travler shouts for an order \"Tow schnappses!\".\n");
printf("Travler: Hah. It'll lift your spirits.\n\n");

printf("[1] Fine, I'll have a drink.\n");
printf("[2] Let's get to the point.\n");

int choice7;
scanf("%d",&choice7);

if (choice7 != 1 && choice7 != 2) {
  while(choice7 != 1 && choice7 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice7);}
}

if (choice7 == 1) {
  printf("Geralt: Little drink won't hurt I guess.\n");
  printf("Travler: So... Yennefer of Vengerberg?\n");
  printf("Gerlat: Never mentioned her name.\n");
  printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

  printf("[1] How do you know Yennefer?\n");
  printf("[2] Who might you be?\n"); }

if (choice7 == 2) {
  printf("Geralt: Finding her - that'll lift my spirits.\n");
  printf("Travler: You look haggard. It's just a few drops to improve your mood.\n");
  printf("A little schnappsie's never hurt a soul.\n");
  printf("Geralt: Can we cut to the chase? You seen her or not?\n");
  printf("Travler: Yennefer of Vengerberg?\n");
  printf("Gerlat: Never mentioned her name.\n");
  printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

  printf("[1] How do you know Yennefer?\n");
  printf("[2] Who might you be?\n");
}

int choice8;
scanf("%d",&choice8);

if (choice8 != 1 && choice8 != 2) {
  while(choice8 != 1 && choice8 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice8);}
}

  if (choice8 == 1) {
    printf("Geralt: So how do you know Yennefer?\n");
    printf("Travler: What a question. Master Dandelion's ballads, of course.");
    printf("Travler: They only way a humbke merchant might hope to rub up against greatness.\n");
    printf("Travler: Unless, that is he's as lucky as I am.\n");
    printf("Geralt: And runs into a very patient witcher?\n");
    printf("Travler: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

    printf("press [Enter] to ask the traveler who he is. \n");
    char myChar15 = 0;
        while (myChar15 != '\n' && myChar15  != '\r') {
            myChar15 = getchar();}

    printf("Geralt: What do you do? Who are you?\n");
    printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
    printf("Geralt: Vagrant - is that a profession now?\n");
    printf("Gaunter: Ah, once a merchant of mirrors.\n");
    printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

    printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
    char myChar16 = 0;
        while (myChar16 != '\n' && myChar16  != '\r') {
            myChar16 = getchar();}

  }

  if (choice8 == 2){
    printf("Geralt: What do you do? Who are you?\n");
    printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
    printf("Geralt: Vagrant - is that a profession now?\n");
    printf("Gaunter: Ah, once a merchant of mirrors.\n");
    printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

    printf("press [Enter] to ask the Gaunter How he does know Yennefer.\n.");
    char myChar15 = 0;
        while (myChar15 != '\n' && myChar15  != '\r') {
            myChar15 = getchar();}

            printf("Geralt: So how do you know Yennefer?\n");
            printf("Gaunter: What a question. Master Dandelion's ballads, of course.");
            printf("Gaunter: They only way a humbke merchant might hope to rub up against greatness.\n");
            printf("Gaunter: Unless, that is he's as lucky as I am.\n");
            printf("Geralt: And runs into a very patient witcher?\n");
            printf("Gaunter: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

            printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
            char myChar16 = 0;
                while (myChar16 != '\n' && myChar16  != '\r') {
                    myChar16 = getchar();}
                    getchar();

  }

}
if (choice6 == 2) {
  printf("Geralt: Looking for a woman.\n");
  printf("Travler #1: Ahh, like everyone.\n");
  printf("Geralt: Not like everyon, and not just any woman.\n");
  printf("Geralt: Mine smells of lilca and gooseberries, dresses in black and white.\n");
  printf("Travler shouts for an order \"Tow schnappses!\".\n");
  printf("Travler: Hah. It'll lift your spirits.\n\n");

  printf("[1] Fine, I'll have a drink.\n");
  printf("[2] Let's get to the point.\n");

  int choice7;
  choice7 = scanf("%d",&choice7);

  if (choice7 != 1 && choice7 != 2) {
    while(choice7 != 1 && choice7 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice7);}
}

  if (choice7 == 1) {
    printf("Geralt: Little drink won't hurt I guess.\n");
    printf("Travler: So... Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n"); }


  if (choice7 == 2) {
    printf("Geralt: Finding her - that'll lift my spirits.\n");
    printf("Travler: You look haggard. It's just a few drops to improve your mood.\n");
    printf("A little schnappsie's never hurt a soul.\n");
    printf("Geralt: Can we cut to the chase? You seen her or not?\n");
    printf("Travler: Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n"); }

  int choice8;
  scanf("%d",&choice8);

  if (choice8 != 1 && choice8 != 2) {
    while(choice8 != 1 && choice8 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice8);}
}

    if (choice8 == 1) {
      printf("Geralt: So how do you know Yennefer?\n");
      printf("Travler: What a question. Master Dandelion's ballads, of course.");
      printf("Travler: They only way a humbke merchant might hope to rub up against greatness.\n");
      printf("Travler: Unless, that is he's as lucky as I am.\n");
      printf("Geralt: And runs into a very patient witcher?\n");
      printf("Travler: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

      printf("press [Enter] to ask the traveler who he is. \n");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}

      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
      char myChar16 = 0;
          while (myChar16 != '\n' && myChar16  != '\r') {
              myChar16 = getchar();}

    }

    if (choice8 == 2){
      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask the Gaunter How he does know Yennefer.\n.");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}

              printf("Geralt: So how do you know Yennefer?\n");
              printf("Gaunter: What a question. Master Dandelion's ballads, of course.");
              printf("Gaunter: They only way a humbke merchant might hope to rub up against greatness.\n");
              printf("Gaunter: Unless, that is he's as lucky as I am.\n");
              printf("Geralt: And runs into a very patient witcher?\n");
              printf("Gaunter: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

              printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
              char myChar16 = 0;
                  while (myChar16 != '\n' && myChar16  != '\r') {
                      myChar16 = getchar();}

    }



}
} //choice5 == 2 ends here
if (choice5 == 3) {
  printf("Geralt: Looking for a woman.\n");
  printf("Travler #1: Ahh, like everyone.\n");
  printf("Geralt: Not like everyon, and not just any woman.\n");
  printf("Geralt: Mine smells of lilca and gooseberries, dresses in black and white.\n");
  printf("Travler shouts for an order \"Tow schnappses!\".\n");
  printf("Travler: Hah. It'll lift your spirits.\n\n");

  printf("[1] Fine, I'll have a drink.\n");
  printf("[2] Let's get to the point.\n");

  int choice7;
  scanf("%d",&choice7);

  if (choice7 != 1 && choice7 != 2) {
    while(choice7 != 1 && choice7 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice7);}
}

  if (choice7 == 1) {
    printf("Geralt: Little drink won't hurt I guess.\n");
    printf("Travler: So... Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n"); }


  if (choice7 == 2) {
    printf("Geralt: Finding her - that'll lift my spirits.\n");
    printf("Travler: You look haggard. It's just a few drops to improve your mood.\n");
    printf("A little schnappsie's never hurt a soul.\n");
    printf("Geralt: Can we cut to the chase? You seen her or not?\n");
    printf("Travler: Yennefer of Vengerberg?\n");
    printf("Gerlat: Never mentioned her name.\n");
    printf("Yet you described her perfectly. And once I hear something, I never forget. can't help it.\n\n");

    printf("[1] How do you know Yennefer?\n");
    printf("[2] Who might you be?\n"); }

  int choice8;
  scanf("%d",&choice8);

  if (choice8 != 1 && choice8 != 2) {
    while(choice8 != 1 && choice8 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice8);}
}

    if (choice8 == 1) {
      printf("Geralt: So how do you know Yennefer?\n");
      printf("Travler: What a question. Master Dandelion's ballads, of course.\n");
      printf("Travler: They only way a humbke merchant might hope to rub up against greatness.\n");
      printf("Travler: Unless, that is he's as lucky as I am.\n");
      printf("Geralt: And runs into a very patient witcher?\n");
      printf("Travler: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

      printf("press [Enter] to ask the traveler who he is. \n");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}
              getchar();

      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
      char myChar16 = 0;
          while (myChar16 != '\n' && myChar16  != '\r') {
              myChar16 = getchar();}

    }

    if (choice8 == 2){
      printf("Geralt: What do you do? Who are you?\n");
      printf("Travler: A mangy vagrant. Gaunter o'Dim, at your service.\n");
      printf("Geralt: Vagrant - is that a profession now?\n");
      printf("Gaunter: Ah, once a merchant of mirrors.\n");
      printf("Gaunter: The madding crowd dubbed me Master Mirror, or Man of Glass.\n\n");

      printf("press [Enter] to ask the Gaunter How he does know Yennefer.\n.");
      char myChar15 = 0;
          while (myChar15 != '\n' && myChar15  != '\r') {
              myChar15 = getchar();}
              getchar();

              printf("Geralt: So how do you know Yennefer?\n");
              printf("Gaunter: What a question. Master Dandelion's ballads, of course.\n");
              printf("Gaunter: They only way a humbke merchant might hope to rub up against greatness.\n");
              printf("Gaunter: Unless, that is he's as lucky as I am.\n");
              printf("Geralt: And runs into a very patient witcher?\n");
              printf("Gaunter: Into Geralt of Rivia himself. The Butcher of Blaviken.\n\n");

              printf("press [Enter] to ask to ask Gaunter where is Yennefer.\n");
              char myChar16 = 0;
                  while (myChar16 != '\n' && myChar16  != '\r') {
                      myChar16 = getchar();}

    }
}

//Back to normal.

printf("Geralt: You seen Yennefer?\n");
printf("Gaunter: Deepest apologies, but I must ask. Is this about love?\n\n");

printf("[1] None of your busines.\n");
printf("[2] Of course it's about love.\n");

int choice9;
scanf("%d",&choice9);

if (choice9 != 1 && choice9 != 2) {
  while(choice9 != 1 && choice9 != 2){
  printf("That's not a valid choice.\n");
  scanf("%d",&choice9);}
}

if (choice9 == 1) {
  printf("Geralt: Nonoe of your business.\n");
  printf("Gaunter: Yes, as vagrant I deserve no explanition.\n");
  printf("Geralt: What do you know? Tell me.\n");
  printf("Gaunter: before you appeared, it never occurred to me that might've been Yennefer.\n");
  printf("Gaunter: Who would've have thought...\n");
  printf("Geralt: Get to the point.\n");
  printf("Gaunter: A Nilfgaardian scout from the local garrison saw her.\n");
  printf("Geralt: Where?\n");
  printf("Gaunter: At their camp. she rode in there.\n");
  printf("Gaunter: Dark of night, black and white, gooseberries and... yes I know.\n");
  printf("Gaunter: Had a terse exchange with the garrison commander and race off.\n");
  printf("Geralt: Where to?\n");
  printf("Gaunter: I'm not omniscient. Ask at the garrison.\n");
  printf("Geralt: Thanks.\n\n");

  printf("press [Enter] to leave the inn.\n");
}

if (choice9 == 2) {
  printf("Geralt: Yes, it is about love.\n");
  printf("Gaunter: I see...\n");
  printf("Geralt: What do you know? Tell me.");
  printf("Gaunter: before you appeared, it never occurred to me that might've been Yennefer.\n");
  printf("Gaunter: Who would've have thought...\n");
  printf("Geralt: Get to the point.\n");
  printf("Gaunter: A Nilfgaardian scout from the local garrison saw her.\n");
  printf("Geralt: Where?\n");
  printf("Gaunter: At their camp. she rode in there.\n");
  printf("Gaunter: Dark of night, black and white, gooseberries and... yes I know.\n");
  printf("Gaunter: Had a terse exchange with the garrison commander and race off.\n");
  printf("Geralt: Where to?\n");
  printf("Gaunter: I'm not omniscient. Ask at the garrison.\n");
  printf("Geralt: Thanks.\n\n");

  printf("press [Enter] to leave the inn.\n");
}
char myChar16 = 0;
    while (myChar16 != '\n' && myChar16  != '\r') {
        myChar16 = getchar();}
        getchar();

  printf("As Geralt has left the inn, he was approached by 3 thugs\n");
  printf("Thug #1: Done drinking?\n");
  printf("Geralt: Mhm... \n");
  printf("Thug #1: Then leave.\n");
  printf("Thug #2: Don't want your kind here.\n");
  printf("Geralt: Better round up someone else to help. you three don't stand a chance against me.\n");
  printf("Thug #3: We don't need more people, I'll beat you up by myself.\n");
  printf("Geralt: If I had a bag over my head and my hands tied behind-\n.");
  printf("Geralt: Actually, no. not even then.\n");
  printf("Thug #2: Chet, Lesh, back off. I'll teach this vagrant a lesson, man on freak.\n");

  printf("In this fight Geralt decided not to use his sword.\n");
  printf("Press [Enter] to fight.\n");
  char myChar17 = 0;
      while (myChar17 != '\n' && myChar17  != '\r') {
          myChar17 = getchar();}
          Thug();
  printf("Chet (Thug #1): Sorry master witcher, we will leave you alone.\n");
  printf("Lesh (Thug #2): We will stay out of your way.\n\n");

  printf("Press [Enter] to head to the garrison.\n");
  printf("At this point you will enconter a random monster to fight.\n");
  printf("Since you are heading to the garrison, you are most likely will fight a Drowner.\n");
  printf("If you are lucky you will not fight any monsters.\n");
  char myChar74 = 0;
      while (myChar74 != '\n' && myChar74  != '\r') {
          myChar74 = getchar();}

  int b = rand () % 10;

  if (b > 5) {Drowner();}
  else if (b > 7) {Ghoul();}
  else if (b > 8) {Bandit();}
  else if (b == 8) {WildDogs();}
  else if (b == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

  printf("Geralt has arrived at the military camp, where the garrison is located.\n");
  printf("The gaurds stop Geralt from entering the camp.\n");
  printf("Guard #1: No locals allowed without the express constent of the garrison commnader.\n");
  printf("Geralt: I look like a local to you?\n");
  printf("Guard #2: You look like trouble.\n");
  printf("Geralt: Dead wrong - I make trouble go away. I'm a witcher.\n");
  printf("Guard #1: A witcher...\n");
  printf("Guard #1: Captain Peter Saar Gwynleve in the tower. Turn right, past the gate.\n");
  printf("Geralt: Huh you guys aren't so scary after all. Can even be nice if you want to.\n");
  printf("Guard #1: Don't get accustomed, Nordling. \n");
  printf("Guard #2: To The tower. Go.\n\n");
  printf("Press[Enter] to go the tower.\n");
  char myChar18 = 0;
      while (myChar18 != '\n' && myChar18  != '\r') {
          myChar18 = getchar();}
  printf("When Geralt has arrived he found the garrison having negotiation with a peasant.\n");
  printf("It seems English isn't commander's first language.\n\n");
  printf("Commnader: How much grain will your village give?\n");
  printf("Peasant: Whatever you say, your Excellency.\n");
  printf("The commander stood up and said: Look at my hands. Look! See the calluses?\n");
  printf("Commander: These are not the hands of an \"Excellency\", but of a framer.\n");
  printf("Commander: So we speak peasant to peasant. How much can you give?\n");
  printf("Peasant: Forty bushels.\n");
  printf("Commander: You will give thrity, and that will do.\n");
  printf("Let us settle on it. And I wish to see the transport soon\n");
  printf("Peasant: Ah thank you, sir!. Thank you kindly!.\n");
  printf("The peasant has left the tower. you are free to speak to the commnader.\n\n");
  printf("Press [Enter] to speak to the commander.\n");
  char myChar19 = 0;
      while (myChar19 != '\n' && myChar19  != '\r') {
          myChar19 = getchar();}
  printf("Commander: I summoned only ealdorman and the smith, Willis.\n");
  printf("Commander: But it is said he is a dwarf. You are too tall to be him.\n");
  printf("Geralt: Plan to requisition something from him, too?\n");
  printf("Commander: If it is necessary - yes, of course.");
  printf("Commander: We are in war in case you have not noticed.\n");
  printf("Commander: Who are you? Speak.\n");
  printf("Geralt: Geralt of Rivia. Witcher. \n");
  printf("Commander: This explains why I did not hear your footsteps. What do you seek?\n");
  printf("Geralt: Yennefer of Vengerberg. Where was she headed?\n");
  printf("Commander: That is a military secret.\n");
  printf("Haven't thrown me out yet. Haven't called the guards. so go ahead - what's your price?\n");
  printf("Press [Enter] to continue.\n");
  char myChar20 = 0;
      while (myChar20 != '\n' && myChar20  != '\r') {
          myChar20 = getchar();}
  printf("Commander: There is a griffin in the area. Slay it, and then I shall see what I can do.\n");
  printf("Geralt: It's a deal. Some questions before I start. Know where the griffin has its lair?\n");
  printf("Commander: it kept to the Vulpine Woods at first. I sent a patrol there five young men.\n");
  printf("Commander: A hunter found them two days on. I only recognized them becaue they wore our plates.\n");
  printf("Commander: Since then, the griffin has grown bold. Attacks in villages, fields, on the main road.\n");
  printf("Geralt: Meaning it's abandoned its lair. Gonna have to set a trap.\n");
  printf("Commander: I judge from your tone this will not be easy. What do you require?\n");
  printf("Geralt: I'll need bait, a specific herb - buckthorn. Scent should lure the griffin.\n");
  printf("Commader: Buck.. buckthorn? I do not know this. But I am no fluent yet in the common tongue.\n");
  printf("Geralt: Mhm. Probably mastered the basics though, though - \"hands up\", \"kill them\".\n");
  printf("Commander: No. First came idioms. \"Don't play with fire\" for example.\n");
  printf("Commander: Go to Tomira, an herbalist. She lives near the crossroads. She will aid you.\n\n");

  printf("Press [Enter] to ask more information about the griffin.\n");
  char myChar21 = 0;
      while (myChar21 != '\n' && myChar21  != '\r') {
          myChar21 = getchar();}

  printf("Geralt: Need more information about this griffin. Its sex, why it's abandoned its lair.\n");
  printf("Commander: Shall I bring you witnesses?\n");
  printf("Geralt: They won't say anything I don't know. I need to go where your men died, look around.\n");
  printf("Geralt: What's the name of the hunter who found them?");
  printf("Commander: Mislav. he has a hut south of the village, very near the wood.\n");
  printf("Commander: Helpful fellow. A little strange, though. \n");
  printf("Geralt: Tomira and Mislav... Thanks.\n\n");

  printf("[1] Go to Mislav (The Hunter)\n");
  printf("[2] Go to Tomira (The Herbalist)\n");

  int choice10;
  scanf("%d",&choice10);

  if (choice10 != 1 && choice10 != 2) {
    while(choice10 != 1 && choice10 != 2){
    printf("That's not a valid choice.\n");
    scanf("%d",&choice10);}
}

  if (choice10 == 1){
    int b = rand () % 10;

    if (b > 3) {Drowner();}
    else if (b > 5) {Ghoul();}
    else if (b > 7) {Bandit();}
    else if (b >= 8) {WildDogs();}
    else if (b == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

    printf("Geralt have arrived at Mislav's hut, as he knocked the door, where there is no answer.\n");
    printf("Geralt: Must be out hunting.\n");
    printf("Geralt decided to investegate the surronding as he found Mislav's footprints.\n");
    printf("Geralt followed the footprints, where eventually he found Mislav.\n\n");
    printf("press [Enter] to speak to Mislav.\n");
    char myChar25 = 0;
        while (myChar25 != '\n' && myChar25  != '\r') {
            myChar25 = getchar();}
    printf("Geralt: You Mislav?\n");
    printf("Mislav:Shhh!.\n");
    printf("Mislav: Hear that?\n");
    printf("Geralt: Wolves? No - wild dogs.\n");
    printf("Mislav: Yes... more dangerous than wolves.\n");
    printf("Geralt: I'm hunting bigger game. The Nilfgaardians the griffin killed.\n");
    printf("Where'd you find them?\n");
    printf("Mislav: Ah, I see... You a witcher?\n");
    printf("That monster slayer they's talkin' about in the village.\n");
    printf("Geralt:Mhm.\n");
    printf("Mislav: I'll show you, sure. But,er, I gotta kill those mutts 'fore they hurt someone.\n");
    printf("Mislav: Will you help? That is, if you don't mind bluntin' your silver blades on 'em.\n");
    printf("Geralt: Sure, griffin isn't going anywhere.\n");
    printf("Mislav: No, dogs might, though. So step careful, now. Come on. \n\n");

    printf("press [Enter] to follow Mislav.\n");
    char myChar26 = 0;
        while (myChar26 != '\n' && myChar26  != '\r') {
            myChar26 = getchar();}

    printf("Mislav: Ok, there two of them, you take one and I will take the other.\n");
    printf("Geralt: Mhm.\n");

    printf("press [Enter] to fight the wild dog.\n");
    char myChar27 = 0;
        while (myChar27 != '\n' && myChar27  != '\r') {
            myChar27 = getchar();}
    WildDogs();

    printf("Geralt: So can you show me where is the Nilfgaardians?.\n");
    printf("Mislav: Follow me.\n\n");

    printf("press [Enter] to follow Mislav.\n");
    char myChar28 = 0;
        while (myChar28 != '\n' && myChar28  != '\r') {
            myChar28 = getchar();}

    printf("Mislav: Twas here.\n");
    printf("Mislav: One lay there, by the stump, headless.\n");
    printf("Mislav: The other hung from a branch, guts splayed, strechin' down to..\n");
    printf("Mislav: Watch out for yourself now. \n");
    printf("Geralt: I'll be fine. Not the first I've dealt with.\n");
    printf("Mislav: Good Huntin' now. \n\n");

    printf("Press [Enter] to investegate the area\n");
    char myChar29 = 0;
        while (myChar29 != '\n' && myChar29  != '\r') {
            myChar29 = getchar();}

    printf("Upon the investegation Geralt believes the Nilfgaardians were celebrating in this area.\n");
    printf("Geralt also found footprints of the Nilfgaardians.\n\n");

    printf("Press [Enter] to follow the footprints.\n");
    printf("you are likely to fight a monster at this point.\n");
    char myChar30 = 0;
        while (myChar30 != '\n' && myChar30  != '\r') {
            myChar30 = getchar();}
    int d = rand () % 10;

    if (d > 4) {Ghoul();}
    else if (d > 6) {Bandit();}
    else if (d >= 8) {WildDogs();}
    else if (d == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

    printf("The footprints have lead to remains of Griffin's nest.\n");
    printf("There is also a dead griffin, which is female.\n");
    printf("Geralt believes the other griffin is male.");
    printf("Geralt also believes male griffin is being aggresive, because the Nilfgaardians.\n");
    printf("has killed its partner. \n\n");

    printf("Press [Enter] to go to Tomira (The Herbalist)\n");
    char myChar72 = 0;
        while (myChar72 != '\n' && myChar72  != '\r') {
            myChar72 = getchar();}
            int c = rand () % 10;

            if (c > 3) {Drowner();}
            else if (c > 4) {Ghoul();}
            else if (c > 6) {Bandit();}
            else if (c >= 8) {WildDogs();}
            else if (c == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

            printf("Geralt has arrived at Tomira's hut.\n");
            printf("Geralt went inside the hut and Tomira treating some girl who is severely injured\n");
            printf("Geralt: Bad time?.\n");
            printf("Tomira: Not at all. Hand me the beggartick. it's the...\n");
            printf("Geralt handed the herb to Tomira.\n");
            printf("Tomira: ...red bloom. Well, well, one versed in herbs.\n");
            printf("Geralt: Probably saying too much... but I know a bit.\n");
            printf("Geralt: For instance,  that beggartick's poisonous.\n");
            printf("Tomira: In large doses. Small ones soothe pain and bring forth pleasant dreams.\n");
            printf("Tomira: Which all I can do for her...\n\n");

            printf("Press [Enter] to ask Tomira about buckthorn.\n");
            char myChar22 = 0;
                while (myChar22 != '\n' && myChar22  != '\r') {
                    myChar22 = getchar();}
                    getchar();

            printf("Geralt: Looking for buckthorn. Know if it grows anywhere around here?\n");
            printf("Tomira: Mhm. Bottom of the river. Where the channel's widest.\n");
            printf("Tomira: But you do know that once out of water...\n");
            printf("Geralt: ...it'll stink worse than a week-old carcass? Counting on it.\n");
            printf("Tomira: Oh yes the griffin. Might've guess.\n");
            printf("Geralt: Thanks.\n");

            printf("press [Enter] to go to the river\n");
            char myChar23 = 0;
                while (myChar23 != '\n' && myChar23  != '\r') {
                    myChar23 = getchar();}

            printf("As Geralt arrived at the river he encountered 2 Drowners\n");
            Drowner();
            Drowner();
            printf("Now you got the drowners out of the way time to look for buckthorn.\n");
            printf("Press [Enter] to look for buckthorn\n");
            char myChar71 = 0;
                while (myChar71 != '\n' && myChar71  != '\r') {
                    myChar71 = getchar();}

            printf("You have found the buckthorn!\n");
            printf("Geralt decided to go and talk to Vesemir.\n\n");
            printf("The Game Ends here for now.\n");

  } //TO

  if (choice10 == 2){
    int b = rand () % 10;

    if (b > 3) {Drowner();}
    else if (b > 5) {Ghoul();}
    else if (b > 7) {Bandit();}
    else if (b >= 8) {WildDogs();}
    else if (b == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

    printf("Geralt has arrived at Tomira's hut.\n");
    printf("Geralt went inside the hut and Tomira treating some girl who is severely injured\n");
    printf("Geralt: Bad time?.\n");
    printf("Tomira: Not at all. Hand me the beggartick. it's the...\n");
    printf("Geralt handed the herb to Tomira.\n");
    printf("Tomira: ...red bloom. Well, well, one versed in herbs.\n");
    printf("Geralt: Probably saying too much... but I know a bit.\n");
    printf("Geralt: For instance,  that beggartick's poisonous.\n");
    printf("Tomira: In large doses. Small ones soothe pain and bring forth pleasant dreams.\n");
    printf("Tomira: Which all I can do for her...\n\n");

    printf("Press [Enter] to ask Tomira about buckthorn.\n");
    char myChar22 = 0;
        while (myChar22 != '\n' && myChar22  != '\r') {
            myChar22 = getchar();}
            getchar();

    printf("Geralt: Looking for buckthorn. Know if it grows anywhere around here?\n");
    printf("Tomira: Mhm. Bottom of the river. Where the channel's widest.\n");
    printf("Tomira: But you do know that once out of water...\n");
    printf("Geralt: ...it'll stink worse than a week-old carcass? Counting on it.\n");
    printf("Tomira: Oh yes the griffin. Might've guess.\n");
    printf("Geralt: Thanks.\n");

    printf("press [Enter] to go to the river\n");
    char myChar23 = 0;
        while (myChar23 != '\n' && myChar23  != '\r') {
            myChar23 = getchar();}

    printf("As Geralt arrived at the river he encountered 2 Drowners\n");
    Drowner();
    Drowner();
    printf("Now you got the drowners out of the way time to look for buckthorn.\n");
    printf("Press [Enter] to look for buckthorn\n");
    char myChar71 = 0;
        while (myChar71 != '\n' && myChar71  != '\r') {
            myChar71 = getchar();}

    printf("You have found the buckthorn!\n");
    printf("Press [Enter] to go to Mislav (The Hunter)\n");
    char myChar72 = 0;
        while (myChar72 != '\n' && myChar72  != '\r') {
            myChar72 = getchar();}
            int c = rand () % 10;

            if (c > 3) {Drowner();}
            else if (c > 4) {Ghoul();}
            else if (c > 6) {Bandit();}
            else if (c >= 8) {WildDogs();}
            else if (c == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}


    printf("Geralt have arrived at Mislav's hut, as he knocked the door, where there is no answer.\n");
    printf("Geralt: Must be out hunting.\n");
    printf("Geralt decided to investegate the surronding as he found Mislav's footprints.\n");
    printf("Geralt followed the footprints, where eventually he found Mislav.\n\n");
    printf("press [Enter] to speak to Mislav.\n");
    char myChar25 = 0;
        while (myChar25 != '\n' && myChar25  != '\r') {
            myChar25 = getchar();}
    printf("Geralt: You Mislav?\n");
    printf("Mislav:Shhh!.\n");
    printf("Mislav: Hear that?\n");
    printf("Geralt: Wolves? No - wild dogs.\n");
    printf("Mislav: Yes... more dangerous than wolves.\n");
    printf("Geralt: I'm hunting bigger game. The Nilfgaardians the griffin killed.\n");
    printf("Where'd you find them?\n");
    printf("Mislav: Ah, I see... You a witcher?\n");
    printf("That monster slayer they's talkin' about in the village.\n");
    printf("Geralt:Mhm.\n");
    printf("Mislav: I'll show you, sure. But,er, I gotta kill those mutts 'fore they hurt someone.\n");
    printf("Mislav: Will you help? That is, if you don't mind bluntin' your silver blades on 'em.\n");
    printf("Geralt: Sure, griffin isn't going anywhere.\n");
    printf("Mislav: No, dogs might, though. So step careful, now. Come on. \n\n");

    printf("press [Enter] to follow Mislav.\n");
    char myChar26 = 0;
        while (myChar26 != '\n' && myChar26  != '\r') {
            myChar26 = getchar();}

    printf("Mislav: Ok, there two of them, you take one and I will take the other.\n");
    printf("Geralt: Mhm.\n");

    printf("press [Enter] to fight the wild dog.\n");
    char myChar27 = 0;
        while (myChar27 != '\n' && myChar27  != '\r') {
            myChar27 = getchar();}
WildDogs();

    printf("Geralt: So can you show me where is the Nilfgaardians?.\n");
    printf("Mislav: Follow me.\n\n");

    printf("press [Enter] to follow Mislav.\n");
    char myChar28 = 0;
        while (myChar28 != '\n' && myChar28  != '\r') {
            myChar28 = getchar();}

    printf("Mislav: Twas here.\n");
    printf("Mislav: One lay there, by the stump, headless.\n");
    printf("Mislav: The other hung from a branch, guts splayed, strechin' down to..\n");
    printf("Mislav: Watch out for yourself now. \n");
    printf("Geralt: I'll be fine. Not the first I've dealt with.\n");
    printf("Mislav: Good Huntin' now. \n\n");

    printf("Press [Enter] to investegate the area\n");
    char myChar29 = 0;
        while (myChar29 != '\n' && myChar29  != '\r') {
            myChar29 = getchar();}

    printf("Upon the investegation Geralt believes the Nilfgaardians were celebrating in this area.\n");
    printf("Geralt also found footprints of the Nilfgaardians.\n\n");

    printf("Press [Enter] to follow the footprints.\n");
    printf("you are likely to fight a monster at this point.\n");
    char myChar30 = 0;
        while (myChar30 != '\n' && myChar30  != '\r') {
            myChar30 = getchar();}
    int d = rand () % 10;

   if (d > 4) {Ghoul();}
  else if (d > 6) {Bandit();}
  else if (d >= 8) {WildDogs();}
  else if (d == 9) {printf("You are lucky, you haven't encountered any monsters.\n");}

    printf("The footprints have lead to remains of Griffin's nest.\n");
    printf("There is also a dead griffin, which is female.\n");
    printf("Geralt believes the other griffin is male.");
    printf("Geralt also believes male griffin is being aggresive, because the Nilfgaardians.\n");
    printf("has killed its partner. \n");
    printf("Geralt decided to go and talk to Vesemir.\n\n");
    printf("The Game Ends here for now.\n");
  }

}
