// This Functions checks if xhunter service provided by xigncode is already running or not, if not running so there is a cheater playing around the game
int CheckServiceRunning()
{
	int STATUS = STATUS_SUCCESS;

	HANDLE hDriver = CreateFile("\\\\.\\xhunter1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hDriver == INVALID_HANDLE_VALUE)
	{
		STATUS = DETECT_SERVICE_NOT_RUNNING;
		SendDetect("[DETECT] XHunter Service is not running", STATUS);
		return STATUS;
	}

	return STATUS;
}
