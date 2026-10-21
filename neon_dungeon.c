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
void viewMap(char map[6][8]){
    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
void Stats(){
    printf("\nPLAYER STATISTICS\n");
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
    char map[6][8] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '@', '.', '.', '$', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', 'E', '.', '.', '#'},
        {'#', '#', '#', '.', '#', '.', 'X', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'}
    };
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
                viewMap(map);
                Stats();
                break;
            case 2:
                Guide();
                break;
            case 3:
                printf("Bye!!! Thank you for coming.");
                return 0;
            default:
                printf("Invalid Choice");
                break;
        }
    }
    return 0;
}