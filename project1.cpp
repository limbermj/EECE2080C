/*
 * Project Title:
 * - The Pirate Adventure Game
 * Description:
 * This program allows the user to go on an adventure for hidden treasure.
 * The game is text based role playing game much like Zork. In this case the win condition
 * is exploring the ship until you have the necessary items to find and unlock the hidden treasure chest.
 *
 * Developers:
 * - Michael Limberg - limbermj@mail.uc.edu
 * - Sean Gatje - gatjesm@mail.uc.edu
 *
 * Help Received:
 * - TA for the 11am wednesday Lab in Old Chem 815
 * - Adedepo Alabi
 *
 *
 *
 * Developer comments:
 * Developer 1: Michael Limberg
 * I wrote the first half of the program while discussing syntax and logic with Sean, and then he took over and I watched for syntax errors and helped remind him of any information he may have forgotten.
 * I learned a lot about function and conditionals that I did not know before this project. There are specific things that I learned here that would have helped me a ton in previous labs, even solving some of my previous problems.
 * Developer 2: Sean Gatje
 * I helped Michael with the logic that we could follow as well as searched for syntax errors that he may have made while writting the code. I then took over the writting aspect after a couple hours while he helped me with syntax.
 * we both worked together on the game design and gameplay. This lab helped me use functions inside of eachother as well as learn how to change values of variables through multiple functions.
 */

#include <iostream>
#include <string>
using namespace std;


void ShipDeck(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CargoHold(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CargoHold2(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CargoHold3(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CrowsNest(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CapQuarter(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void CapQuarter2(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void Chest(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);
void DarkCave(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank);


/* Function Name: DarkCave
 *
 * Function Description:
 * This function solves is the starting point for the game and marks the point at which someone will respawn if they die. This is in other words the first room.
 * also resets all of the item values to 0 when you die.
 *
 * Parameters:
 * choose the correct method to enter the ship.
 *
 * return value:
 * does not have a return, but moves the player onto the next level/room in this case the Ship deck.
 */
void DarkCave(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    lamp = 0;
    gunpowder = 0;
    knife = 0;
    key = 0;
    ladder = 0;
    plank = 0;

    string LorP;
    cout<<"On the ground next to you you see a ladder and a plank in a pile. "
          "Would you like to get onto the ship with the ladder or the plank?: ";
    cin>>LorP;
    cin.ignore();
    if(LorP == "ladder"){
        ladder = 1;
        cout<<"You prop the LADDER against the ship and climb aboard."<<endl;
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(LorP == "plank"){
        plank = 1;
        cout<<"As you're tip-toeing across the PLANK, it snaps, and you fall into the heavily shark "
              "infested water below."<<endl;
        cout<<endl;
        cout<<"YOU ARE DEAD!"<<endl;
        cout<<endl;
        cout<<endl;
        DarkCave( lamp, gunpowder, knife, key, ladder, plank);
    }
    else{
        cout<<"Enter a valid option."<<endl;
        cout<<endl;
        cout<<endl;
        DarkCave( lamp, gunpowder, knife, key, ladder, plank);
    }
}

/* Function Name: ShipDeck
 *
 * Function Description:
 *ShipDeck allows you to access 3 other rooms on the ship. In some ways it is the main room of the game.
 *
 * Parameters:
 * You enter the name of the room you would like to go and it will send you to that room's function.
 *
 * return value:
 * No specific return, but it will send you to either the captain's quarters, cargo hold, or crows nest depending on your input.
 *
 */
void ShipDeck(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    string deckLocation;
    cout<<"Where would you like to go? The cargo hold, crows nest, or captain's quarters?: ";
    getline(cin, deckLocation);
    if(deckLocation == "cargo hold"){
        cout<<endl;
        CargoHold( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(deckLocation == "crows nest"){
        cout<<endl;
        CrowsNest( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(deckLocation == "captain's quarters"){
        cout<<endl;
        CapQuarter( lamp, gunpowder, knife, key, ladder, plank);
    }else{
        cout<<endl;
        cout<<"Enter Valid Location!"<<endl;
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
    }

}

/* Function Name: CrowsNest
 *
 * Function Description:
 * This function allows the user to enter the crows nest room/level.
 * The user then picks up a lamp which will allow them to enter other rooms.
 *
 * Parameters:
 * The user enters the room, picks up the lamp, changing lamp from 0 to which other rooms will recognize as an item acquisition.
 *
 * return value:
 * The user returns to the ship deck as it "returns" the ShipDeck fucntion.
 */
void CrowsNest(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    lamp = 1;
    cout<<"You climb the steap ladder to the crows nest and find a LAMP. You realize this could be helpful and pick it up."<<endl;
    cout<<endl;
    ShipDeck( lamp, gunpowder, knife, key, ladder, plank);

}

/* Function Name: CargoHold
 *
 * Function Description:
 * This function checks to see if the user has acquired the lamp from the crows nest.
 * This is kind of like a gateway for the cargo hold.
 *
 * Parameters:
 * If the user has the lamp, they will enter CargoHold2.
 * Otherwise the user will return to ShipDeck
 *
 * return value:
 * The user is returned to the ShipDeck or continues to CargoHold2 if they have the lamp.
 */
void CargoHold(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    if(lamp == 1){
        cout<<"The LAMP illuminates the cargo hold and you enter."<<endl;
        CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
    }else{
        cout<<"Its too dark to see you need to find a LAMP!"<<endl;
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
       }
}

/* Function Name: CargoHold2
 *
 * Function Description:
 * This function acts as the cargo hold room. you can search the room for items that will aid you later in the game.
 *
 * Parameters:
 * You can search a crate, barrel, or cage, additionally you can continue deeper into the hold to the secret room.
 * Furthermore you can prompt the program to go back to the ship deck.
 * you will find items which will change their value form 0 to 1 allowing other rooms to recognize their acquisition.
 *
 * return value:
 * You can continue to the secret room, or return to the ship deck.
 */
void CargoHold2(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    string CargoDis;
    cout<<"You see a crate, a barrel, an empty cage that is covered in spider webs, and a door leading deeper into the hold."<<endl;
    cout<<"Would you like to check the crate, the cage, the barrel, go to the deck, or go deeper into the hold?"<<endl;
    cout<<"('crate', 'cage', 'barrel', 'deck', 'deeper'): ";
    cin>>CargoDis;
    if(CargoDis == "crate"){
        cout<<endl;
        cout<<"You find a rusty old pirate KNIFE and pick it up."<<endl;
        cout<<endl;
        knife = 1;
        CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(CargoDis == "barrel"){
        cout<<endl;
        cout<<"You find some GUNPOWDER and pick it up."<<endl;
        gunpowder = 1;
        cout<<endl;
        CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(CargoDis == "cage"){
        cout<<endl;
        cout<<"You stick your hand into the cage and discover that it was home to a LARGE POISENOUS SPIDER."<<endl;
        cout<<"IT BITES YOU!"<<endl;
        cout<<"YOU ARE DEAD!!!"<<endl;
        cout<<endl;
        cout<<endl;
        DarkCave( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(CargoDis == "deeper"){
        cout<<endl;
       CargoHold3( lamp, gunpowder, knife, key, ladder, plank);
    }else if(CargoDis == "deck"){
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
    }else{
        cout<<endl;
        cout<<"Enter a valid response"<<endl;
        cout<<endl;
        CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
    }
}

/* Function Name: CargoHold3
 *
 * Function Description:
 * This function checks to see if you have gunpowder on your person in order to get into the secret room.
 * You then enter the secret room and find the key for the treasure chest.
 *
 * Parameters:
 * If gunpowder is 1 then you will be allowed to procede to the secret room. If gunpowder is still 0 then you dont have the capability to open the door.
 *
 *
 * return value:
 * If you have gunpowder then you are sent to the secret room and pick up the key for the treasure chest.
 * Then you are asked to go to either the hold or the ship deck.
 * Otherwise you are returned to the cargo hold room.
 *
 */
void CargoHold3(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    string cord;
    cout<<"You come to a large locked wooden door that is barely on it's hindges"<<endl;
    cout<<endl;
    if(gunpowder == 0){
        cout<<"You have NOTHING to blow the hindges off of the door."<<endl;
        cout<<endl;
        CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
    }
    else{
        key = 1;
        cout<<"You place the GUNPOWDER infront of the door and light it with your LAMP to blow off its hindges."<<endl;
        cout<<endl;
        cout<<"You find a KEY as you search the room."<<endl;
        cout<<endl;
        cout<<"Would you like to go back to the entrance of the cargo hold or the deck('hold' or 'deck')?: ";
        cin>>cord;
        if(cord == "deck"){
            cout<<endl;
            ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
         }
        else if(cord == "hold"){
            cout<<endl;
            CargoHold2( lamp, gunpowder, knife, key, ladder, plank);
        }
    }
}

/* Function Name: CapQuarter
 *
 * Function Description:
 * This function checks to see if you have the knie acquired from the cargo room.
 * It acts as a gateway for the captain quarter's room.
 *
 * Parameters:
 * If the knife is equal to 1 then you can enter the room otherwise you havent acquired the knife and you cant enter.
 *
 *
 * return value:
 * you can continue to the captain's quarters room if you have the knife to open the door.
 * Otherwise you are sent back to the ship deck.
 */
void CapQuarter(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    if(knife == 0){
        cout<<"The strongest sailor's knot you've ever seen is keeping the door is TIED SHUT. It won't budge."<<endl;
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
    }
    else{
        cout<<"You cut the sailors knot from the door with your KNIFE and enter the room."<<endl;
        cout<<endl;
        CapQuarter2( lamp, gunpowder, knife, key, ladder, plank);
    }
}

/* Function Name: CapQuarter2
 *
 * Function Description:
 * You search for the chest in the captains quarter room.
 *
 * Parameters:
 * You can search behind a desk in a hole in the wall, or underneath a skeleton.
 *
 *
 * return value:
 * you are returned to the beginning of the game if you move the desk because it causes the room to fall on you.
 * You find the chest if you move the skeleton.
 *
 */
void CapQuarter2(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    string ObjectMove;
    cout<<"You quickly glance around the room and see no chest."<<endl;
    cout<<endl;
    cout<<"But you see a desk covering a hole in the wall and a skeleton laying on top of a blanket covering something."<<endl;
    cout<<endl;
    cout<<"Do you want to move the desk or the skeleton?: ";
    cin>>ObjectMove;
    if(ObjectMove == "skeleton") {
        cout<<endl;
        cout<<"You move the skeleton and find that he was laying on the TREASURE."<<endl;
        cout<<endl;
        Chest( lamp, gunpowder, knife, key, ladder, plank);
    }
    else if(ObjectMove == "desk"){
        cout<<"You move the LOAD BEARING DESK out of the way and the room collapses on top of you."<<endl;
        cout<<endl;
        cout<<"YOU ARE DEAD!!!"<<endl;
        cout<<endl;
        cout<<endl;
        DarkCave( lamp, gunpowder, knife, key, ladder, plank);
    }
}

/* Function Name: Chest
 *
 * Function Description:
 * This function checks to see if you have the key.
 * This is kind of like a gateway for winning the game.
 *
 * Parameters:
 * The function checks to see if you have the key, if you have acquired the key, then you win the game.
 * If you dont have the key then you are sent back to the ship deck.
 *
 *
 * return value:
 * You are told you win the game and the game ends if you have a key, or you dont have the key and you are sent to the ship deck.
 *
 */
void Chest(int& lamp,int& gunpowder,int& knife,int& key,int& ladder,int& plank){
    if(key == 1){
        cout<<"You use your key to open the treasure chest to find tons of glittering gold."<<endl;
        cout<<endl;
        cout<<"YOU WIN!!!!"<<endl;
        cout<<endl;
        cout<<endl;
    }
    else{
        cout<<"You need a key to open the chest."<<endl;
        cout<<endl;
        cout<<"You return to the deck in despair"<<endl;
        cout<<endl;
        ShipDeck( lamp, gunpowder, knife, key, ladder, plank);
    }
}


int main()
{
    int lamp = 0;
    int gunpowder = 0;
    int knife = 0;
    int key = 0;
    int ladder = 0;
    int plank = 0;
    cout<<"You find yourself in a dark cave in search of the Pirate treasure."<<endl;
    cout<<endl;
    cout<<"Your research tells you that the treasure is located somewhere in the captains chamber of the ship ahead of you."<<endl;
    cout<<endl;
    cout<<"Once on the ship you also know that there is a dark cargo hold, a secret room, a crows nest, and the captains chamber."<<endl;
    cout<<endl;
    DarkCave( lamp, gunpowder, knife, key, ladder, plank);

    return 0;
}
