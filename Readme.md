# 참고

## 디렉토리 정리
```
project/
│
├── data/                # 데이터 파일 저장 (e.g., CSV, JSON)
│   ├── raw/             # 원본 데이터
│   ├── processed/       # 전처리된 데이터
│
├── notebooks/           # Jupyter Notebook (.ipynb) 파일
│   ├── analysis.ipynb
│   ├── visualization.ipynb
│
├── src/                 # 소스코드 파일 (e.g., Python, C++, etc.)
│   ├── main.py
│   ├── utils.py
│   ├── models/
│   │   ├── regression.py
│   │   ├── neural_net.py
│
├── tests/               # 테스트 코드 (e.g., unit tests)
│   ├── test_utils.py
│   ├── test_models.py
│
├── docs/                # 문서화 (README, 프로젝트 설명)
│   ├── README.md
│   ├── requirements.txt
│   ├── documentation.pdf
│
├── results/             # 결과물 (e.g., 시각화, 모델 출력)
│   ├── figures/
│   ├── logs/
│
└── environment/         # 환경 관련 파일
    ├── environment.yml  # Conda 환경 파일
    ├── requirements.txt # pip 요구 사항
```

## Git

### System Config
- 시스템의  모든 사용자와 모든 저장소에 적용   
```
git config --system
```

### Global Config
- 시스템의 특정 사용자에게 적용   
```
git config --global
```

### Local Config
- 특정 저장소에 적용   
```
git config --local
```

### Usernmae & Email
```
git config user.name <name>
git config user.email <email>
```

### CRLF
```
git config core,.autocrlf <value>
```

- Line Ending은 OS마다 다름
    - Windows: CR(\r) + LF(\n)
    - Unix or Mac: LF(\n)

### Editor
```
git config core.editor <editor>
```

### Default Branch
```
git config init.defaultBranch <name>
```

### Git 전체 설정 확인
```
git config -l
git config --list
```

### Git 설치 범위 별 전체 설정 확인
```
git config --list --show-origin
```

### Git 개별 설정 확인
```
git config <key>
```

### Git log
- 해당 저장소의 Commit 이력을 시간순으로 보여준다

- 기본
```
git log
```

- 최근 Commit 개수 지정   
```
git log -2
```

- 건너뛸 로그 개수 지정   
```
git log --skip 5
```

- diff 같이 출력   
```
git log -p
```

- 한 줄로 출력   
```
git log --oneline
```

- 사용자에 따른 검색   
```
git log --author=<user.name or user.email>
```

- 파일 변경 사항으로 검색   
```
git log -S <검색어>
```

### Remote

- Remote 저장소 추가   
```
git remnote add <name> <remote_repository_url>
```

- Remote 저장소 기본 이름   
```
git remote add origin <remote_repository_url>
```

- Remote 저장소 주소 수정   
```
git remote set-url origin <remote_repository_url>
```

- Remote 저장소 이름 수정   
```
git remote rename <old_name> <new_name>
```

- Remote 저장소 삭제   
```
git remote remove <name>
```

- Remote 저장소 정보 확인   
```
git remote -v
```

- Remote 저장소 상세 보기
```
git remote show <name>
```

### Pull
- Remote Repository의 작업 내용을 Local Repository에 동기화
- Fetch와 Merge의 과정

- 기본   
```
git pull <name> <branch_name>
```
- 예제   
```
git pull origin main
```

### Push

- 기본   
```
git push <name> <branch_name>
```
- 예제   
```
git push origin main
```

### Clone

- 과정   
```
mkdir -> Git init -> Git Remote add -> Git Pull
```

### Git checkout
- 특정 버전으로 이동   
```
git checkout <commit_id>
```

### Git Branch 목록
- Local   
```
git branch
```

- Remote   
```
git branch -r
```

- All   
```
git branch -a
```

### Git Branch 생성
- Local   
```
git branch <branch_name>
```

- 간지용   
```
git checkout -b <branch_name>
```

### Git Branch 배포 - Remote
```
git push origin <branch_name>
```

### Git Branch 삭제 
- Local   
```
git branch --delete <branch_name>
```

- Remote   
```
git push origin --delete <branch_name>
```

### Git remote branch 연결 확인
```
git branch -vv
```

### Git Merge
- 현재 위치한 버전에 다른 버전을 병합하는 작업
- Branch를 병합하거나
- Push Pull 할 때도 일어난다

- 기본
```
git merge <branch_name>
```

### Git Conflict 
- Git status로 파악할 수 있다
- Merge 과정에서 충돌 발생시 가운데 =====를 기준으로 충돌 부분을 보여주는데 이를 기준으로 코드 수정

### Git Tag

- 기본
```
git tag <tagname>
```

- Tag 목록 보기
```
git tag
```

- 특정 버전에 Tag 생성
```
git tag <tagname> <commit_id>
```
