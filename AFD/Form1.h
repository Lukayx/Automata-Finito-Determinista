#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used


#include "Header2.h"

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void)
    {
      InitializeComponent();
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::TextBox^ out_textBox;
  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::TextBox^ txt_estadoInicial;
  private: System::Windows::Forms::TextBox^ txt_estadosFinales;
  private: System::Windows::Forms::Button^ boton_transiciones;
  private: System::Windows::Forms::Label^ Titulo1;
  private: System::Windows::Forms::Label^ Titulo2;
  private: System::Windows::Forms::TextBox^ txt_palabra;
  private: System::Windows::Forms::Button^ boton_usarAFD;
  private: System::Windows::Forms::Button^ boton_leerPalabra;
  private: System::Windows::Forms::Button^ boton_limpiarInfo;
  private: ArrayList^ arregloSimbolos = gcnew ArrayList();
  private: array<int>^ nodosYestados;
  private: int estadoInicial;





  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->out_textBox = (gcnew System::Windows::Forms::TextBox());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->txt_estadosFinales = (gcnew System::Windows::Forms::TextBox());
        this->boton_transiciones = (gcnew System::Windows::Forms::Button());
        this->Titulo1 = (gcnew System::Windows::Forms::Label());
        this->Titulo2 = (gcnew System::Windows::Forms::Label());
        this->txt_palabra = (gcnew System::Windows::Forms::TextBox());
        this->boton_usarAFD = (gcnew System::Windows::Forms::Button());
        this->boton_leerPalabra = (gcnew System::Windows::Forms::Button());
        this->boton_limpiarInfo = (gcnew System::Windows::Forms::Button());
        this->txt_estadoInicial = (gcnew System::Windows::Forms::TextBox());
        this->SuspendLayout();
        // 
        // out_textBox
        // 
        this->out_textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
            | System::Windows::Forms::AnchorStyles::Left)
            | System::Windows::Forms::AnchorStyles::Right));
        this->out_textBox->Location = System::Drawing::Point(514, 22);
        this->out_textBox->Multiline = true;
        this->out_textBox->Name = L"out_textBox";
        this->out_textBox->Size = System::Drawing::Size(347, 335);
        this->out_textBox->TabIndex = 0;
        this->out_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::out_textBox_TextChanged);
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(73, 70);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(83, 15);
        this->label1->TabIndex = 2;
        this->label1->Text = L"Estado Inicial:";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(73, 107);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(97, 15);
        this->label2->TabIndex = 3;
        this->label2->Text = L"Estados Finales:";
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(57, 267);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(146, 15);
        this->label3->TabIndex = 5;
        this->label3->Text = L"Ingrese la palabra a leer: ";
        // 
        // txt_estadosFinales
        // 
        this->txt_estadosFinales->ForeColor = System::Drawing::SystemColors::ScrollBar;
        this->txt_estadosFinales->Location = System::Drawing::Point(187, 106);
        this->txt_estadosFinales->Name = L"txt_estadosFinales";
        this->txt_estadosFinales->Size = System::Drawing::Size(242, 20);
        this->txt_estadosFinales->TabIndex = 7;
        this->txt_estadosFinales->Text = L"Ejemplo: 3,5,7";
        this->txt_estadosFinales->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->txt_estadosFinales->Enter += gcnew System::EventHandler(this, &Form1::txt_estadosFinales_Enter);
        this->txt_estadosFinales->Leave += gcnew System::EventHandler(this, &Form1::txt_estadosFinales_Leave);
        // 
        // boton_transiciones
        // 
        this->boton_transiciones->Location = System::Drawing::Point(178, 141);
        this->boton_transiciones->Name = L"boton_transiciones";
        this->boton_transiciones->Size = System::Drawing::Size(149, 37);
        this->boton_transiciones->TabIndex = 9;
        this->boton_transiciones->Text = L"Ver Transiciones de Estados";
        this->boton_transiciones->UseVisualStyleBackColor = true;
        this->boton_transiciones->Click += gcnew System::EventHandler(this, &Form1::boton_Transiciones_Click);
        // 
        // Titulo1
        // 
        this->Titulo1->AutoSize = true;
        this->Titulo1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Titulo1->Location = System::Drawing::Point(46, 32);
        this->Titulo1->Name = L"Titulo1";
        this->Titulo1->Size = System::Drawing::Size(410, 20);
        this->Titulo1->TabIndex = 10;
        this->Titulo1->Text = L"DEFINIR EL AUTOMATA FINITO DETERMINISTA";
        // 
        // Titulo2
        // 
        this->Titulo2->AutoSize = true;
        this->Titulo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->Titulo2->Location = System::Drawing::Point(119, 220);
        this->Titulo2->Name = L"Titulo2";
        this->Titulo2->Size = System::Drawing::Size(265, 20);
        this->Titulo2->TabIndex = 11;
        this->Titulo2->Text = L"DEFINIR LA PALABRA A LEER";
        // 
        // txt_palabra
        // 
        this->txt_palabra->BackColor = System::Drawing::Color::White;
        this->txt_palabra->Enabled = false;
        this->txt_palabra->ForeColor = System::Drawing::SystemColors::ScrollBar;
        this->txt_palabra->Location = System::Drawing::Point(209, 266);
        this->txt_palabra->Name = L"txt_palabra";
        this->txt_palabra->Size = System::Drawing::Size(232, 20);
        this->txt_palabra->TabIndex = 12;
        this->txt_palabra->Text = L"Ejemplo: \"00110100\"";
        this->txt_palabra->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        // 
        // boton_usarAFD
        // 
        this->boton_usarAFD->Enabled = false;
        this->boton_usarAFD->Location = System::Drawing::Point(50, 309);
        this->boton_usarAFD->Name = L"boton_usarAFD";
        this->boton_usarAFD->Size = System::Drawing::Size(118, 37);
        this->boton_usarAFD->TabIndex = 13;
        this->boton_usarAFD->Text = L"Usar este AFD";
        this->boton_usarAFD->UseVisualStyleBackColor = true;
        this->boton_usarAFD->Click += gcnew System::EventHandler(this, &Form1::boton_usarAFD_Click);
        // 
        // boton_leerPalabra
        // 
        this->boton_leerPalabra->Enabled = false;
        this->boton_leerPalabra->Location = System::Drawing::Point(195, 309);
        this->boton_leerPalabra->Name = L"boton_leerPalabra";
        this->boton_leerPalabra->Size = System::Drawing::Size(118, 37);
        this->boton_leerPalabra->TabIndex = 14;
        this->boton_leerPalabra->Text = L"Leer Palabra";
        this->boton_leerPalabra->UseVisualStyleBackColor = true;
        this->boton_leerPalabra->Click += gcnew System::EventHandler(this, &Form1::boton_leerPalabra_Click);
        // 
        // boton_limpiarInfo
        // 
        this->boton_limpiarInfo->Enabled = false;
        this->boton_limpiarInfo->Location = System::Drawing::Point(338, 309);
        this->boton_limpiarInfo->Name = L"boton_limpiarInfo";
        this->boton_limpiarInfo->Size = System::Drawing::Size(118, 37);
        this->boton_limpiarInfo->TabIndex = 15;
        this->boton_limpiarInfo->Text = L"Limpiar Información";
        this->boton_limpiarInfo->UseVisualStyleBackColor = true;
        this->boton_limpiarInfo->Click += gcnew System::EventHandler(this, &Form1::boton_limpiarInfo_Click);
        // 
        // txt_estadoInicial
        // 
        this->txt_estadoInicial->ForeColor = System::Drawing::SystemColors::ScrollBar;
        this->txt_estadoInicial->Location = System::Drawing::Point(187, 69);
        this->txt_estadoInicial->Name = L"txt_estadoInicial";
        this->txt_estadoInicial->Size = System::Drawing::Size(242, 20);
        this->txt_estadoInicial->TabIndex = 16;
        this->txt_estadoInicial->Text = L"Ingrese el numero del estado inicial";
        this->txt_estadoInicial->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->txt_estadoInicial->Enter += gcnew System::EventHandler(this, &Form1::txt_estadoInicial_Enter);
        this->txt_estadoInicial->Leave += gcnew System::EventHandler(this, &Form1::txt_estadoInicial_Leave);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(887, 385);
        this->Controls->Add(this->txt_estadoInicial);
        this->Controls->Add(this->boton_limpiarInfo);
        this->Controls->Add(this->boton_leerPalabra);
        this->Controls->Add(this->boton_usarAFD);
        this->Controls->Add(this->txt_palabra);
        this->Controls->Add(this->Titulo2);
        this->Controls->Add(this->Titulo1);
        this->Controls->Add(this->boton_transiciones);
        this->Controls->Add(this->txt_estadosFinales);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->out_textBox);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.

   void MyForm_Load(Object^ sender, EventArgs^ e)
   {

   }

   private: System::Void read_initial_state(System::Object^ sender, System::EventArgs^ e) 
   {

   }
/*
  private: System::Void button_plus_1_Click(System::Object^ sender, System::EventArgs^ e)
  {
    int n = Convert::ToInt32(in_textBox->Text);
    int result = N_header_1::plus_1(n);
    out_textBox->AppendText(String::Format("plus_1({0})={1}\r\n", n, result));
  }

  private: System::Void button_plus_2_Click(System::Object^ sender, System::EventArgs^ e)
  {
    N_header_2::plus_2_Click(in_textBox, out_textBox);
  }
  */

private: System::Void boton_Transiciones_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ estadoInicial = txt_estadoInicial->Text;
    String^ estadosFinales = txt_estadosFinales->Text;
    int numero;
    if (!Int32::TryParse(estadoInicial, numero) || numero < 0)
    {
        MessageBox::Show(String::Format("Error de formato en estado inicial.\n Verifique que sea un estado inicial valido"));
        return;
    }
    array<String^>^ finales = estadosFinales->Split(',');
    for each (String^ nodo in finales)
    {
        if (!Int32::TryParse(nodo, numero) || numero < 0) 
        {
            MessageBox::Show(String::Format("Error de formato en estados finales.\n Verifique que los numeros sean positivos y estén separados por comas."));
            return;
        }
    }



}

private: System::Void txt_estadoInicial_Enter(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadoInicial->Text == "Ingrese el numero del estado inicial")
    {
        txt_estadoInicial->Text = "";
        txt_estadoInicial->ForeColor = System::Drawing::SystemColors::MenuText;
    }
}

private: System::Void txt_estadoInicial_Leave(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadoInicial->Text == "")
    {
        txt_estadoInicial->ForeColor = System::Drawing::SystemColors::ScrollBar;
        txt_estadoInicial->Text = "Ingrese el numero del estado inicial";
    }
}

private: System::Void txt_estadosFinales_Enter(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadosFinales->Text == "Ejemplo: 3,5,7")
    {
        txt_estadosFinales->Text = "";
        txt_estadosFinales->ForeColor = System::Drawing::SystemColors::MenuText;
    }
}

private: System::Void txt_estadosFinales_Leave(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadosFinales->Text == "")
    {
        txt_estadosFinales->ForeColor = System::Drawing::SystemColors::ScrollBar;
        txt_estadosFinales->Text = "Ejemplo: 3,5,7";
    }
}

private: System::Void CheckButtonEnabled() {
    if (txt_estadosFinales->Text != "" && txt_estadoInicial->Text != "") 
    {
        boton_transiciones->Enabled = true;
    }
    else 
    {
        boton_transiciones->Enabled = false;
    }
}

private: System::Void boton_usarAFD_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void boton_leerPalabra_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void boton_limpiarInfo_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void out_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}







}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

