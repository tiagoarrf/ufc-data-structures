#!/bin/bash
#By Tiago A. Fontenele
# 06/04/2021

clear
echo " Compilando o programa..."
chmod +x makefile
./makefile
if [ $? -eq 0 ]
then
   echo " Programa Iniciado..."
   echo ""
   echo "exit" > 6n7t5u8d4a57489.txt
   ./programa < 6n7t5u8d4a57489.txt
   rm 6n7t5u8d4a57489.txt
   rm temp/* &> /dev/null
   echo ""
   echo " Programa finalizado."
   echo " Gerando os gráficos..."
   gnuplot --version &> /dev/null
   if [ $? -eq 0 ]
   then
      gnuplot plot/vet_graf_insertion.p
      gnuplot plot/vet_graf_selection.p
      gnuplot plot/vet_graf_merge.p
      gnuplot plot/vet_graf_quick.p
      gnuplot plot/vet_graf_shell.p
      gnuplot plot/vet_todos.p
      gnuplot plot/list_graf_insertion.p
      gnuplot plot/list_graf_selection.p
      gnuplot plot/list_graf_merge.p
      gnuplot plot/list_graf_quick.p
      gnuplot plot/list_graf_shell.p
      gnuplot plot/list_todos.p
   echo " Gráficos salvos na pasta: graficos"
   else
      echo " Erro ao gerar os gráficos."
      echo " Gnuplot não está instalado! Use: sudo apt-get install gnuplot"
   fi
else
  echo " Erro ao tentar compilar o programa!"
fi
echo " Processo finalizado."
