#include <stdio.h>
struct Player
{
    int health;
    int keys;
    int gold;
};
struct Player player;
void Menu(){
    printf("\n=============================\n");
    printf("        Neon Dungeon\n");
    printf("=============================\n");
    printf("\n");
    printf("\n");
    printf("A Terminal Adventure");
    printf("\n");
    printf("\n");
    printf("1.Start Game\n");
    printf("2.How to play\n");
    printf("3.Exit\n");
    printf("Enter your choice:");
}
void Stats(){
    printf("PLAYER STATISTICS\n");
    printf("Health:%d\n",player.health);
    printf("Gold:%d\n",player.gold);
    printf("Keys:%d\n",player.keys);
}
void Guide(){
    printf("================ HOW TO PLAY ================\n");
    printf("\n");
    printf("\n");
    printf("Your mission is to escape the dungeon.\n");
    printf("\n");
    printf("Explore the map and collect treasure.\n Avoid enemies and protect your health. \nFind the key to unlock the exit.\n");
    printf("\n");
    printf("Your starting statistics:\nHealth: 100\nGold: 0\nKeys: 0");
}
int main(){
    int choice;
    player.health=100;
    player.gold=0;
    player.keys=0;
    while (1)
    {
        Menu();
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                Stats();
                break;
            case 2:
                Guide();
                break;
            case 3:
                printf("Bye!!! Thank you for coming.");
                return 0;
            default:
                break;
        }
    }
    return 0;
}