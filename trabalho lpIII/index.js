// Definição da classe
class Pessoa {
    // Construtor
    constructor(nome, idade) {
      this.nome = nome;
      this.idade = idade;
    }
  
    // Método para imprimir os dados da pessoa
    imprimirDados() {
      const dados = `Nome: ${this.nome}, idade: ${this.idade}`;
      document.querySelector("p").textContent = dados;
    }
  }
  
  // Criação de uma instância da classe
  const pessoa = new Pessoa();
  
  // Adicionando um evento de submit ao formulário
  document.querySelector("form").addEventListener("submit", function(e) {
    // Cancelando o envio do formulário
    e.preventDefault();
  
    // Obtendo os dados do formulário
    const nome = document.querySelector("input[name='nome']").value;
    const idade = document.querySelector("input[name='idade']").value;
  
    // Colocando os dados no objeto
    pessoa.nome = nome;
    pessoa.idade = idade;
  
    // Imprimindo os dados da pessoa
    pessoa.imprimirDados();
  });
  