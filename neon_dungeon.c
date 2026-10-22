    #include <stdio.h>
    struct Player
    {
        int health;
        int keys;
        int gold;
    };
    struct Position
    {
        int row;
        int column;
    };
    struct Player player;
    struct Position p;
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
            printf("Enter Q to exit to main menu");
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
                    printf("================================\n          TREASURE DISCOVERED!\n================================\n\n  You found 25 gold!\n\nYour total gold:%d",player.gold);
                }
                else
                    p.column+=1;
                break;
            case 'q':
            case 'Q':
                return 0;
            default:
                printf("Invalid Choice");
                break;
            }
        }
        
    }
    int main(){
        int choice;
        char map[6][8] = {
            {'#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '.', '.', '.', '$', '.', '.', '#'},
            {'#', '.', '#', '.', '#', '#', '.', '#'},
            {'#', '.', '.', '.', 'E', '.', '.', '#'},
            {'#', '#', '#', '.', '#', '.', 'X', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#'}
        };
        char posplayer[6][8];
        p.row=1;
        p.column=1;
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