import tkinter as tk

def confirm_selection():
    robot_name = robot_entry.get()
    room_name = room_entry.get()
    message = f"Você selecionou o robô {robot_name} na sala {room_name}."
    tk.messagebox.showinfo("Seleção", message)

root = tk.Tk()
root.title("Seleção de Robô e Sala")

robot_label = tk.Label(root, text="Nome do Robô:")
robot_label.pack()

robot_entry = tk.Entry(root)
robot_entry.pack()

room_label = tk.Label(root, text="Nome da Sala:")
room_label.pack()

room_entry = tk.Entry(root)
room_entry.pack()

confirm_button = tk.Button(root, text="Confirmar", command=confirm_selection)
confirm_button.pack()

root.mainloop()
