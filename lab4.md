## Laboratory work 4



## Tasks

- [ ] 1. Создать публичный репозиторий с названием **lab04** и с лиценцией **MIT**

- [ ] 2. Сгенирировать токен для доступа к сервису **GitHub** с правами **repo**
![image](https://github.com/user-attachments/assets/4cbe0f11-45af-439f-907d-537d7b548cbe)



## Tutorial

```sh
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ export GITHUB_TOKEN=<сгенирированный_токен>
$ alias edit=<nano|vi|vim|subl>
```


```sh
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```



```sh
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```

```sh
$ mkdir projects/lab04 && cd projects/lab04
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04.git
$ git pull origin master
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master
```

![image](https://github.com/user-attachments/assets/8f9d1665-c957-4514-8db2-8e5f8b246ab3)


Добавить на сервисе **GitHub** в репозитории **lab04** файл **.gitignore**
со следующем содержимом:

```sh
*build*/
*install*/
*.swp
.idea/
```

![image](https://github.com/user-attachments/assets/dae78b4f-0970-49a5-a8bc-c8bf8881f060)
![image](https://github.com/user-attachments/assets/c948c89f-99cb-49bd-b3f7-109af74f1f91)


```sh
$ git pull origin master
$ git log
```

```sh
$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```

![image](https://github.com/user-attachments/assets/a7999049-2818-4de2-82d6-42711a36d2db)

![image](https://github.com/user-attachments/assets/48c9fd03-8e91-4e2d-bce6-46b7f0bcba6b)

```sh
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```
```sh
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF
```

```sh
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```

```sh
$ edit README.md
```

```sh
$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin master
```
![image](https://github.com/user-attachments/assets/c97a5ab9-c41d-496e-a7c7-5c6415da7ce9)


## Report

```sh
$ cd ~/workspace/
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```
## Links

- [hub](https://hub.github.com/)
- [GitHub](https://github.com)
- [Bitbucket](https://bitbucket.org)
- [Gitlab](https://about.gitlab.com)
- [LearnGitBranching](http://learngitbranching.js.org/)

```
Copyright (c) 2015-2025 The ISC Authors
```
