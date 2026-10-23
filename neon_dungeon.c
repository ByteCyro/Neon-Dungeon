    #include <stdio.h>
    #include <stdlib.h>
    struct Player
    {
        int health;
        int keys;
        int gold;
        int damage;
    };
    struct Position
    {
        int row;
        int column;
    };
    struct Enemy
    {
        int health;
        int damage;
    };
    struct Player player;
    struct Position p;
    struct Enemy enemy;
    int retreat=0;
    char posplayer[6][8];
    char map[6][8];
    void Menu();
    void viewMap(char map[6][8]);
    void Stats();
    void Guide();
    void playerPos(char map[6][8],char posplayer[6][8]);
    void viewPlayerposition(char posplayer[6][8]);
    void combat();
    void enemyEncounter();
    int movement(char posplayer[6][8],char map[6][8]);
    void reset();

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
        printf("\n========================================");
        printf("\nPLAYER STATISTICS\n");
        printf("Health:%d\n",player.health);
        printf("Gold:%d\n",player.gold);
        printf("Keys:%d\n",player.keys);
        printf("========================================\n\n");
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
    void playerPos(char map[6][8],char posplayer[6][8]){
        for(int i=0;i<6;i++){
            for(int j=0;j<8;j++){
                posplayer[i][j]=map[i][j];
            }
        }
        posplayer[p.row][p.column]='@';
    }
    void viewPlayerposition(char posplayer[6][8]){
        for(int i=0;i<6;i++){
            for(int j=0;j<8;j++){
                printf("%c",posplayer[i][j]);
            }
            printf("\n");
        }   
    }
    void combat(){
        printf("========================================\n               COMBAT\n========================================\n\nYou attacked the enemy!\n");
            enemy.health=enemy.health-player.damage;
            if(enemy.health<=0){
                enemy.health=0;
            }
            printf("Enemy received damage: %d\n",player.damage);
            printf("Enemy health: %d\n",enemy.health);
            printf("\n");
            if(enemy.health!=0){
            printf("The enemy retaliates!\n\n");
            player.health=player.health-enemy.damage;
            if(player.health<=0){
                player.health=0;
            }
            printf("Your Health:%d\n",player.health);
            }
    }
    void enemyEncounter(){
        int option;
                    while (1)
                    {
                        printf("\n1.Attack");
                        printf("\n2.Retreat");
                        printf("\nChoose Your option:");
                        scanf(" %d",&option);
                        switch (option)
                        {
                            case 1:
                                combat();
                                break;
                            case 2:
                                printf("You retreated from combat!\n");
                                printf("Your Health:%d",player.health);
                                retreat=1;
                                return;
                            default:
                                printf("Invalid choice!");
                                break;
                        }
                        if (enemy.health==0){
                            printf("========================================\n             ENEMY DEFEATED!\n========================================\n\nYou defeated the enemy!");
                            printf("\nRemaining health: %d\n",player.health);
                            break;
                        }
                        if(player.health==0){
                            printf("========================================\n               GAME OVER\n========================================\n\nYou were defeated in the dungeon.\n");
                            printf("Gold Collected:%d\n",player.gold);
                            printf("Health:%d\n\n",player.health);
                            printf("Better luck next time!");
                            exit(0);
                        }
                    }
                    
    }
    int movement(char posplayer[6][8],char map[6][8]){
        char key;
        while (1)
        {
            playerPos(map,posplayer);
            viewPlayerposition(posplayer);
            printf("Enter W to move up\n");
            printf("Enter S to move down\n");
            printf("Enter A to move left\n");
            printf("Enter D to move right\n");
            printf("Enter I to view stats\n");
            printf("Enter Q to exit to main menu\n");
            scanf(" %c",&key);
            switch (key)
            {
            case 'w':
            case 'W':
                if(map[p.row-1][p.column]=='#')
                    printf("The destination is wall position is not changed\n");
                else if (map[p.row-1][p.column]=='$')
                {
                    player.gold+=25;
                    p.row-=1;
                    map[p.row][p.column]='.';
                    printf("================================\n          TREASURE DISCOVERED!\n================================\n\n  You found 25 gold!\n\nYour total gold:%d",player.gold);
                }
                else if (map[p.row-1][p.column]=='E')
                {   
                    printf("================================\n         ENEMY ENCOUNTER\n================================\n\nAn enemy blocks your path!");
                    printf("\nYour Health:%d\n",player.health);
                    printf("Enemy Health:%d\n",enemy.health);
                    enemyEncounter();
                    if(!retreat){
                        p.row-=1;
                        map[p.row][p.column]='.';   
                    }
                }
                else if (map[p.row-1][p.column]=='K')
                {
                    player.keys+=1;
                    p.row-=1;
                    printf("================================\n          KEY DISCOVERED!\n================================\n\n  You have found a key!\n\nYour total keys:%d\n",player.keys);
                    map[p.row][p.column]='.';
                }
                else if (map[p.row-1][p.column]=='X')
                {
                    printf("================================\n          EXIT DISCOVERED!\n================================\n\n");
                    if(player.keys<=0){
                        printf("Exit is locked you need a key to escape!\n");
                    }
                    else{
                        printf("========================================\n          DUNGEON COMPLETED!\n=========================================\n\nCongratulations! You escaped the Neon Dungeon!");
                        printf("\nFinal Statistics:\n");
                        printf("Health:%d\n",player.health);
                        printf("Gold Collected:%d\n",player.gold);
                        printf("Keys Collected:%d\n",player.keys);
                        printf("\nThanks for playing the dungeon!!!");
                        exit(0);
                    }
                    }
                else
                    p.row-=1;
                break;
            case 's':
            case 'S':
                if(map[p.row+1][p.column]=='#')
                    printf("The destination is wall position is not changed\n");
                else if (map[p.row+1][p.column]=='$')
                {
                    player.gold+=25;
                    p.row+=1;
                    map[p.row][p.column]='.';
                    printf("================================\n          TREASURE DISCOVERED!\n================================\n\n  You found 25 gold!\n\nYour total gold:%d",player.gold);
                }
                else if (map[p.row+1][p.column]=='E')
                {
                    printf("================================\n         ENEMY ENCOUNTER\n================================\n\nAn enemy blocks your path!");
                    printf("\nYour Health:%d\n",player.health);
                    printf("Enemy Health:%d\n",enemy.health);
                    enemyEncounter();
                    if(!retreat){
                        p.row+=1;
                        map[p.row][p.column]='.';   
                    }
                }
                else if (map[p.row+1][p.column]=='K')
                {
                    player.keys+=1;
                    p.row+=1;
                    printf("================================\n          KEY DISCOVERED!\n================================\n\n  You have found a key!\n\nYour total keys:%d",player.keys);
                    map[p.row][p.column]='.';
                }
                else if (map[p.row+1][p.column]=='X')
                {
                    printf("================================\n          EXIT DISCOVERED!\n================================\n\n");
                    if(player.keys<=0){
                        printf("Exit is locked you need a key to escape!\n");
                    }
                    else{
                        printf("========================================\n          DUNGEON COMPLETED!\n=========================================\n\nCongratulations! You escaped the Neon Dungeon!");
                        printf("\nFinal Statistics:\n");
                        printf("Health:%d\n",player.health);
                        printf("Gold Collected:%d\n",player.gold);
                        printf("Keys Collected:%d\n",player.keys);
                        printf("\nThanks for playing the dungeon!!!");
                        exit(0);
                    }
                }
                else
                    p.row+=1;
                break;
            case 'a':
            case 'A':
                if(map[p.row][p.column-1]=='#')
                    printf("The destination is wall position is not changed\n");
                else if (map[p.row][p.column-1]=='$')
                {
                    player.gold+=25;
                    p.column-=1;
                    map[p.row][p.column]='.';
                    printf("================================\n          TREASURE DISCOVERED!\n================================\n\n  You found 25 gold!\n\nYour total gold:%d",player.gold);
                }
                else if (map[p.row][p.column-1]=='E')
                {
                    printf("================================\n         ENEMY ENCOUNTER\n================================\n\nAn enemy blocks your path!");
                    printf("\nYour Health:%d\n",player.health);
                    printf("Enemy Health:%d\n",enemy.health);
                    enemyEncounter();
                    if(!retreat){
                        p.column-=1;
                        map[p.row][p.column]='.';   
                    }
                }
                else if (map[p.row][p.column-1]=='K')
                {
                    player.keys+=1;
                    p.column-=1;
                    printf("================================\n          KEY DISCOVERED!\n================================\n\n  You have found a key!\n\nYour total keys:%d",player.keys);
                    map[p.row][p.column]='.';
                }
                else if (map[p.row][p.column-1]=='X')
                {
                    printf("================================\n          EXIT DISCOVERED!\n================================\n\n");
                    if(player.keys<=0){
                        printf("Exit is locked you need a key to escape!\n");
                    }
                    else{
                        printf("========================================\n          DUNGEON COMPLETED!\n=========================================\n\nCongratulations! You escaped the Neon Dungeon!");
                        printf("\nFinal Statistics:\n");
                        printf("Health:%d\n",player.health);
                        printf("Gold Collected:%d\n",player.gold);
                        printf("Keys Collected:%d\n",player.keys);
                        printf("\nThanks for playing the dungeon!!!");
                        exit(0);
                    } 
                }
                else
                    p.column-=1;
                break;
            case 'd':
            case 'D':
                if(map[p.row][p.column+1]=='#')
                    printf("The destination is wall position is not changed\n");
                else if (map[p.row][p.column+1]=='$')
                {
                    player.gold+=25;
                    p.column+=1;
                    map[p.row][p.column]='.';
                    printf("================================\n          TREASURE DISCOVERED!\n================================\n\n  You found 25 gold!\n\nYour total gold:%d\n",player.gold);
                }
                else if (map[p.row][p.column+1]=='E')
                {
                    printf("================================\n         ENEMY ENCOUNTER\n================================\n\nAn enemy blocks your path!\n");
                    printf("\nYour Health:%d\n",player.health);
                    printf("Enemy Health:%d\n",enemy.health);
                    enemyEncounter();
                    if(!retreat){
                        p.column+=1;
                        map[p.row][p.column]='.';   
                    }
                }
                else if (map[p.row][p.column+1]=='K')
                {
                    player.keys+=1;
                    p.column+=1;
                    printf("================================\n          KEY DISCOVERED!\n================================\n\n  You have found a key!\n\nYour total keys:%d\n",player.keys);
                    map[p.row][p.column]='.';
                }
                else if (map[p.row][p.column+1]=='X')
                {
                    printf("================================\n          EXIT DISCOVERED!\n================================\n\n");
                    if(player.keys<=0){
                        printf("Exit is locked you need a key to escape!\n");
                    }
                    else{
                        printf("========================================\n          DUNGEON COMPLETED!\n=========================================\n\nCongratulations! You escaped the Neon Dungeon!");
                        printf("\nFinal Statistics:\n");
                        printf("Health:%d\n",player.health);
                        printf("Gold Collected:%d\n",player.gold);
                        printf("Keys Collected:%d\n",player.keys);
                        printf("\nThanks for playing the dungeon!!!");
                        exit(0);
                    }
                }
                else
                    p.column+=1;
                break;
            case 'i':
            case 'I':
                Stats();
                break;
            case 'q':
            case 'Q':
               return 0;
            default:
                printf("Invalid Choice");
                break;
            }
            retreat=0;
        }
        
    }
    void reset(){
        char map[6][8] = {
                        {'#', '#', '#', '#', '#', '#', '#', '#'},
                        {'#', '.', '.', '.', '$', '.', '.', '#'},
                        {'#', '.', '#', '.', '#', '#', '.', '#'},
                        {'#', '.', '.', '.', 'E', '.', '.', '#'},
                        {'#', '#', '#', 'K', '#', '.', 'X', '#'},
                        {'#', '#', '#', '#', '#', '#', '#', '#'}
                    };
                    char posplayer[6][8];
                    p.row=1;
                    p.column=1;
                    player.health=100;
                    player.gold=0;
                    player.keys=0;
                    player.damage=20;
                    enemy.damage=10;
                    enemy.health=50;
    }
    int main(){
        int choice;
        while(1){
            Menu();
            scanf("%d",&choice);
            printf("\n");
            switch (choice)
            {
                case 1:
                    reset();
                    movement(posplayer,map);
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