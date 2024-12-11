class Carta:
    def __init__(self, estado, codigo, nome, populacao, area, pib, pontos_turisticos):
        self.estado = estado
        self.codigo = codigo
        self.nome = nome
        self.populacao = populacao
        self.area = area
        self.pib = pib
        self.pontos_turisticos = pontos_turisticos
        self.densidade_populacional = self.calcular_densidade_populacional()
        self.pib_per_capita = self.calcular_pib_per_capita()

    def calcular_densidade_populacional(self):
        return self.populacao / self.area

    def calcular_pib_per_capita(self):
        return (self.pib * 1e9) / self.populacao

    def calcular_super_poder(self):
        return self.populacao + self.area + (self.pib * 1e9) + self.pontos_turisticos

    def exibir_dados(self):
        print(f"\n=== Carta {self.codigo} ===")
        print(f"Estado: {self.estado}")
        print(f"Nome da Cidade: {self.nome}")
        print(f"População: {self.populacao:,} habitantes")
        print(f"Área: {self.area:.2f} km²")
        print(f"PIB: {self.pib:.2f} bilhões de reais")
        print(f"Pontos Turísticos: {self.pontos_turisticos}")
        print(f"Densidade Populacional: {self.densidade_populacional:.2f} hab/km²")
        print(f"PIB per capita: R$ {self.pib_per_capita:,.2f}")

def validar_entrada_numerica(mensagem, tipo='float'):
    while True:
        try:
            valor = input(mensagem)
            if tipo == 'float':
                numero = float(valor)
            else:
                numero = int(valor)
            if numero <= 0:
                print("Por favor, digite um valor positivo.")
                continue
            return numero
        except ValueError:
            print("Entrada inválida. Digite um número válido.")

def cadastrar_carta():
    print("\n=== Cadastro de Nova Carta ===")
    
    estado = input("Digite o estado (A-H): ").upper()
    while not (len(estado) == 1 and 'A' <= estado <= 'H'):
        print("Estado inválido. Use letras de A a H.")
        estado = input("Digite o estado (A-H): ").upper()

    codigo = input("Digite o código da carta (exemplo: A01): ").upper()
    while not (len(codigo) == 3 and codigo[0] == estado and codigo[1:].isdigit()):
        print("Código inválido. Use o formato: letra do estado + número (ex: A01)")
        codigo = input("Digite o código da carta: ").upper()

    nome = input("Digite o nome da cidade: ")
    populacao = validar_entrada_numerica("Digite a população: ", 'int')
    area = validar_entrada_numerica("Digite a área (km²): ")
    pib = validar_entrada_numerica("Digite o PIB (em bilhões): ")
    pontos_turisticos = validar_entrada_numerica("Digite o número de pontos turísticos: ", 'int')

    return Carta(estado, codigo, nome, populacao, area, pib, pontos_turisticos)

def comparar_cartas(carta1, carta2):
    print("\n=== Comparação entre Cartas ===")
    print(f"Comparando {carta1.codigo} ({carta1.nome}) vs {carta2.codigo} ({carta2.nome})")
    print("\nResultados:")

    comparacoes = {
        "População": (carta1.populacao > carta2.populacao, True),
        "Área": (carta1.area > carta2.area, True),
        "PIB": (carta1.pib > carta2.pib, True),
        "Pontos Turísticos": (carta1.pontos_turisticos > carta2.pontos_turisticos, True),
        "Densidade Populacional": (carta1.densidade_populacional < carta2.densidade_populacional, False),
        "PIB per capita": (carta1.pib_per_capita > carta2.pib_per_capita, True)
    }

    for criterio, (resultado, maior_melhor) in comparacoes.items():
        vencedor = carta1.codigo if resultado else carta2.codigo
        print(f"{criterio}: {vencedor} vence")

    super_poder1 = carta1.calcular_super_poder()
    super_poder2 = carta2.calcular_super_poder()
    print(f"Super Poder: {carta1.codigo if super_poder1 > super_poder2 else carta2.codigo} vence")

def main():
    cartas = []
    while True:
        print("\n=== Super Trunfo - Países ===")
        print("1. Cadastrar nova carta")
        print("2. Listar cartas")
        print("3. Comparar cartas")
        print("4. Sair")
        
        opcao = input("\nEscolha uma opção: ")
        
        if opcao == "1":
            carta = cadastrar_carta()
            cartas.append(carta)
            print("\nCarta cadastrada com sucesso!")
            
        elif opcao == "2":
            if not cartas:
                print("\nNenhuma carta cadastrada!")
            else:
                print("\n=== Cartas Cadastradas ===")
                for carta in cartas:
                    carta.exibir_dados()
                    
        elif opcao == "3":
            if len(cartas) < 2:
                print("\nÉ necessário ter pelo menos 2 cartas cadastradas para comparar!")
                continue
                
            print("\nCartas disponíveis:")
            for i, carta in enumerate(cartas):
                print(f"{i+1}. {carta.codigo} - {carta.nome}")
                
            try:
                idx1 = int(input("\nEscolha o número da primeira carta: ")) - 1
                idx2 = int(input("Escolha o número da segunda carta: ")) - 1
                comparar_cartas(cartas[idx1], cartas[idx2])
            except (ValueError, IndexError):
                print("Seleção inválida!")
                
        elif opcao == "4":
            print("\nObrigado por jogar Super Trunfo!")
            break
            
        else:
            print("\nOpção inválida!")

if __name__ == "__main__":
    main()
