
class Conta {

    constructor(numero, saldo = 0) {
        this.numero = numero;
        this.saldo = saldo;
    }

    depositar(valor) {
        this.saldo += valor;
    }

    sacar(valor) {
        if (valor <= this.saldo) {
            this.saldo -= valor;
            return true;
        } else {
            return false;
        }
    }

    consultarSaldo() {
        return this.saldo;
    }

    imprimir() {
        const dados = `Nome: ${this.numero}, idade: ${this.saldo}`;
        document.querySelector("p").textContent = dados;
    }
}

var minhaConta = new Conta(12345, 1000);
document.querySelector("button").addEventListener("click", pessoa.imprimirDados);