
목표 mandatory통과 후 bonus진행. 

얻어갈 수 있는 것 : 
	thread
	프로세스 동기화, 스레드 동기화
	mutex, semaphore
	race condition

필로소퍼의 배열이 있다 
각 필로소퍼의 idx는 각 필로소퍼의 오른쪽 fork의 mutex를 가리킨다. 
뮤텍스 자체를 포크로 사용한다?? 나는 그렇게 하지 않고 실제 fork값이 있고 이를 관리하는 mutex를 두어 사용해야 겠다. 


### 구현 생각

clerk 서기 main thd
philos 철학자들 philo thd

대기열 thread를 두어서 여러명의 철학자를 관리할 수 있도록 할까? 
가비지 컬렉터 - 가비지 컬렉터를 thread를 생성해서 계속해서 필요없는 메모리를 해제하도록 하자. 그런데 어떻게 하지?

홀수 일 때 먼저 식사를 시작하게 해야겠다! 왜냐하면 필로소퍼가 하나일 때 처리해야하기 때문에. 

홀수 : 밥 -> 잠 -> 생각 
짝수 : 생각 -> 밥 -> 잠



### 과제를 진행하면서 찾아본 링크들. 

- https://moonsiri.tistory.com/156 (대기열 서버에 관한 것) 
