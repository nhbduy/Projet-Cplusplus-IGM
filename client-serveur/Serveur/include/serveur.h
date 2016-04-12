//#ifndef SERVEUR_H
//#define SERVEUR_H
//
//#include <winsock2.h>
//
//class serveur;
//
//struct thread_param{
//       serveur* ser;
//       SOCKET soc;
//};
//
//
//class serveur{
//	private:
//		int           port;
//		SOCKET	      ListeningSocket;
//		bool          running;
//		SOCKADDR_IN   ServerAddr;
//		DWORD         ClientThread(SOCKET);
//	public:
//		serveur(int);
//		int                 init();
//		int                 start ();
//		int                 pause ();
//		static DWORD WINAPI ThreadLauncher(void *p){
//			struct thread_param *Obj = reinterpret_cast<struct thread_param*>(p);
//			serveur *s = Obj->ser;
//			return s->ClientThread(Obj->soc);
//		}
//};
//
//#endif // SERVEUR_H
