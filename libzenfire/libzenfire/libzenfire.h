// libzenfire.h

#pragma once

#define BIG_SYS_NO_BOOST

#pragma unmanaged
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

#include <zenfire/sys.hpp>
#include <zenfire/event/Client.hpp>

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std ;

#pragma managed

using namespace System;
using namespace System::Runtime::InteropServices;

interior_ptr<unsigned char> GetAsciiString(System::String ^s)
{
    array<unsigned char> ^chars = System::Text::Encoding::ASCII->GetBytes(s);
    return &chars[0];
}
/*
#pragma unmanaged

LONG __stdcall CatchAll( EXCEPTION_POINTERS* pep );
void HandleAll( EXCEPTION_POINTERS* pep );

LONG __stdcall CatchAll( EXCEPTION_POINTERS* pep )
{
	HandleAll(pep);
	return EXCEPTION_EXECUTE_HANDLER;
}

void HandleAl(l EXCEPTION_POINTERS* pep )
{
	std::cout << "caught an unhandled exception, need to fill in handler here." << std::endl;
}
#pragma managed
*/

namespace libzenfire {
	namespace control {
		public ref class Client {
		public:
		Client(String^ configfilename)
		{
			std::cout << "hello" << std::endl;
			pin_ptr<unsigned char> configfilename_chars = GetAsciiString(configfilename);
			std::string configfilename_str((char*)configfilename_chars);
			/*
			c = NULL;
			try {
				h = new zenfire::event::EventHandler();
			} catch (...) {
				std::cout << "failed to create event handler" << std::endl;
			}

			try {
				c = zenfire::event::Client::create_ini("examples.conf", h);
			} catch (...) {
				std::cout << "failed to create client" << std::endl;
				// TODO make this more specific
				throw gcnew System::Exception();
			} */
		}

		!Client()
		{/*
			if (c != NULL)
			{
				delete c;
				c = NULL;
			}
			if (h != NULL)
			{
				delete h;
				h = NULL;
			} */
		}

		~Client() {}

		private:
		//zenfire::event::EventHandler* h;
		//zenfire::event::Client* c;
		};
	}
}
