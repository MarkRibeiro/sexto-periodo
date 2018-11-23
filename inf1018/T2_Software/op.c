int operacao (char var1, int idx1, char op, char var2, int idx2, int posi)
{
	switch (var1)
	{
		case 'p':
		{
			codigo[posi++]=0x89;
			codigo[posi++]=0xfa;

			break;
		}

		case 'v':
		{
			codigo[posi++]=0x8b;
			codigo[posi++]=0x55;
			codigo[posi++]=0xfc -4* idx1;

			break;
		}

		case '$':
		{
			codigo[posi++]=0xba;
			codigo[posi++]=0xe8;
			codigo[posi++]=idx0 & 0xff;
			codigo[posi++]=(idx0 >> 8) & 0xff;
			codigo[posi++]=(idx0 >> 16) & 0xff;
			codigo[posi++]=(idx0 >> 24) & 0xff;

			break;
		}
	}

	switch (op)
	{
		case '+':
		{
			switch (var2)
			{
				case 'p':
				{
					codigo[posi++]=0x01;
					codigo[posi++]=0xfa;

					break;
				}

				case 'v':
				{
					codigo[posi++]=0x03;
					codigo[posi++]=0x55;
					codigo[posi++]=0xfc -4* idx2;

					break;
				}

				case '$':
				{
					codigo[posi++]=0x81;
					codigo[posi++]=0xc2;
					codigo[posi++]=idx0 & 0xff;
					codigo[posi++]=(idx0 >> 8) & 0xff;
					codigo[posi++]=(idx0 >> 16) & 0xff;
					codigo[posi++]=(idx0 >> 24) & 0xff;

					break;
				}
			}
		}

		case '-':
		{
			switch (var2)
			{
				case 'p':
				{
					codigo[posi++]=0x29;
					codigo[posi++]=0xfa;

					break;
				}

				case 'v':
				{
					codigo[posi++]=0x2b;
					codigo[posi++]=0x55;
					codigo[posi++]=0xfc -4* idx2;

					break;
				}

				case '$':
				{
					codigo[posi++]=0x81;
					codigo[posi++]=0xea;
					codigo[posi++]=idx0 & 0xff;
					codigo[posi++]=(idx0 >> 8) & 0xff;
					codigo[posi++]=(idx0 >> 16) & 0xff;
					codigo[posi++]=(idx0 >> 24) & 0xff;

					break;
				}
			}
			break;
		}

		case '*':
		{
			switch (var2)
			{
				case 'p':
				{
					codigo[posi++]=0x0f;
					codigo[posi++]=0xaf;
					codigo[posi++]=0xd7;

					break;
				}

				case 'v':
				{
					codigo[posi++]=0x0f;
					codigo[posi++]=0xaf;
					codigo[posi++]=0x55;
					codigo[posi++]=0xfc -4* idx2;

					break;
				}

				case '$':
				{
					codigo[posi++]=0x69;
					codigo[posi++]=0xd2;
					codigo[posi++]=idx0 & 0xff;
					codigo[posi++]=(idx0 >> 8) & 0xff;
					codigo[posi++]=(idx0 >> 16) & 0xff;
					codigo[posi++]=(idx0 >> 24) & 0xff;

					break;
				}
			}
		}
		break
	}
	return posi;
}