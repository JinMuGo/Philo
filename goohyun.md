
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

각각의 필로소퍼들에게 멈추라는 신호를 줘야하는데. terminate변수와 mutex를 주어서 끝내게 해야겠다. 
누가 죽었다는 걸다른 필로소퍼에게 알려주면 프로젝트의 룰에 위반되기 때문에 위의 방법을 써야겠군. 
하지만 philo들의 상태는 직접 변경할 수 있지만 
본인이 죽었다는 건 바꿀 수 없기 때문에 clerk가 직접 바꾸어 준다. 
그리고 그렇게 되면 해당 thread말고 다른 thread 는 stop_dining상태가 되어서 모두 
행동을 중단하게 한다. 

### 과제를 진행하면서 찾아본 링크들. 

- https://moonsiri.tistory.com/156 (대기열 서버에 관한 것) 



죽는 거 확인 -> main -> 죽은 자는 말이없음. -> 

main thd -> clerk(서기)역할을 함 -> 메인이 pop하면서 출력함. mt

philo thd mt  -> clerk의 queue에 자신의 상태를 기록합니다. 
-> alert를 보면서 자신이 종료되어야함을 알아챕니다. mt



start_mt 

모든 스레드들이 같은 시간에 식사를 시작할 수 있게 해줌.

