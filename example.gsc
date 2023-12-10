init()
{
	level thread onPlayerConnect();
}
onPlayerConnect()
{
    while(true)
    {
        level waittill("connected", player);
		player thread monitorKeyboard();
	}
}

monitorKeyboard()
{
    self endon("disconnect");

    while(true)
    {
        self waittill( "keyboard_result",id,result);

        if(id == "gamertag_return")
        {
            //returns the string that entered in the xbox keyboard thingy
			self iPrintLn(result);
        }
    }
}

					//keyboard id,description,max characters
					//string can always be returns with the monitorKeyboard loop 
//self XShowKeyboardUI("gamertag_return","Enter your new gamertag",20);

//self SetGamerTag("bot0");
//self SetClantag("FaZe")
//self SetWeaponFlag(2) ( i think 2 is Mala but im not sure)