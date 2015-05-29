#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

int nBerun = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_show;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_show;

int g_nSource = 100000;
int eventOK = 0;

void *ThreadDealMessage(void *pArg) {
  while(nBerun) {
    pthread_mutex_lock(&mutex);
    if (eventOK == 0)
      pthread_cond_wait(&cond, &mutex);
    eventOK = 0;
    pthread_mutex_unlock(&mutex);

    g_nSource--; /* do what you want */
    std::cout << "do..." << std::endl;
  }
  return (void *)pArg;
}

void *ThreadGetMessage(void *pArg) {
  while(1) {
    pthread_mutex_lock(&mutex);
    g_nSource++;
    eventOK = 1;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
  }

  return (void *)pArg;
}

int main() {
  int nRet = 0;
  pthread_t pidMyThread;

  nRet = pthread_create(&pidMyThread, NULL, ThreadDealMessage, NULL);
  if (nRet) {
    std::cout << "pthread_create error" << std::endl;
    exit(1);
  }

  while(1) {
    sleep(3);
    eventOK = 1;
  }


}
