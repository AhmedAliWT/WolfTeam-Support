///////////////////////////////////////////////
// After some reversing I found how to use in-game message function that cheaters uses to spam alot of text to users in game
// this message is a built-in function in the engine itself that showes a big yellow text at the top-left of the screen
// the code below shows how to use this code to call the function and how we can fix it from the server
// Credits: Ahmed ALi
///////////////////////////////////////////////



/////////// Usage of Yellow Message Function
#define MID_PLAYER_TITLE	103
#define MID_PLAYER_MESSAGE	106
static char title[128] = "TestTitle";
static char body[128] = "Hello WolfTeam";

//Sending data to the server to initialize the title of the message
CAutoMessage pMsg;
pMsg.Writeuint8(MID_PLAYER_TITLE);
pMsg.WriteString(title);
pMsg.Writeint32(0);
SendToServer(pMsg.Read(), MESSAGE_GUARANTEED);

//Sending data to all clients to initialize the body and sending the whole message
CAutoMessage cMsg;
cMsg.Writeuint8(MID_PLAYER_MESSAGE);
cMsg.WriteString(message);
cMsg.Writeint32(0);
SendToServer(cMsg.Read(), MESSAGE_GUARANTEED);

//Output
//TestTitle:HellowWolfTeam -> shows with yellow big text

////////////////////////////////////////Solution//////////////////////////////////////////////////////////////////
/// in sdk ObjectDLL/ObjectShared/GameServerShell.cpp  //object.lto
/// you will find onMessage function, that's the function used to handle data from clients to send to other client
/// you will find the function handles a case MID_PLAYER_MESSAGE with id 106, commenting that line fix the problem
void CGameServerShell::OnMessage(HCLIENT hSender, ILTMessage_Read *pMsg)
{
  if( !pMsg )
		return;
  .
  .
  .
   pMsg->SeekTo(0);
	uint8 messageID = pMsg->Readuint8();
	
	switch (messageID)
	{
	//comment this line that handles player message request from clients. id=106
        //case MID_PLAYER_MESSAGE:			HandlePlayerMessage				(hSender, pMsg);	break;  
  }
  
}
// after commenting if any player tried to use that id nothing will appears to other clients and the problem will be fixed.
