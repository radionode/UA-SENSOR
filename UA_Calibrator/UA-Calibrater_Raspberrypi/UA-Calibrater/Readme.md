
[linux 사용법]

1. vi -b UA_Calibrator.sh
vi 의 바이너리 모드로 들어가면 ^M 이라는 문자가 보인다면 이것을 지우면 된다.
또는 dos2unix 커맨드로
linux 콘솔에서 dos2unix UA_Calibrator.sh 와 같이 명령을 주어 파일을 변경한다.

2. 실행권한
chmod +x UA_Calibrator.sh ./bin/UA_Calibrator

3. UA-Series 장치 읽기 쓰기 권한
/dev/ttyACM0 권한 문제
$ sudo usermod -a -G dialout [login user name]
로그아웃 또는 재부팅 하면 된다.

5. UA_Calibrator.sh를 실행한다.

