#include <stdio.h>


int main(){
    printf("Hello, World!\n");//e assim vai commitando
    return 0;   
}


/*
git init    // inicializa o repositório git

git add (nome do arquivo)    //adiciona o arquivo para o próximo commit, ou seja, para o próximo ponto de salvamento do código.

git status   //mostra o status do repositório, ou seja, quais arquivos foram modificados, quais estão prontos para o commit, etc.

git commit -m / git commit -am (ja adiciona commitando) "mensagem do commit"   //cria um commit com as alterações adicionadas e a mensagem fornecida. O commit é um ponto de salvamento no histórico do projeto.

git log / git log --oneline   //mostra o histórico de commits do repositório. O comando "git log" exibe detalhes completos de cada commit, enquanto "git log --oneline" mostra uma versão resumida, com apenas o hash do commit e a mensagem.

git restore (nome do arquivo)   //desfaz as alterações feitas no arquivo

git push -u origin main   //envia os commits locais para o repositório remoto, associando a branch local "main" com a branch remota "origin/main". O comando "git push" é usado para compartilhar as alterações com outros colaboradores ou para atualizar o repositório remoto.

git branch   (nome do branch) -M (novo nome do branch) //renomeia a branch atual para o novo nome especificado. O comando "git branch" é usado para criar, listar ou renomear branches no repositório.

git branch   //mostra a lista de branches no repositório, indicando qual branch está atualmente ativa com um asterisco (*). O comando "git branch" é usado para gerenciar as branches do projeto.*/