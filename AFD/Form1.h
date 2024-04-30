#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
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
  private: System::Windows::Forms::Label^ label4;
  private: System::Windows::Forms::Label^ label5;

  private: System::Windows::Forms::TextBox^ txt_estadosFinales;
  private: System::Windows::Forms::TextBox^ txt_simbolosTransiciones;
  private: System::Windows::Forms::Button^ boton_transiciones;
  private: System::Windows::Forms::Label^ Titulo1;
  private: System::Windows::Forms::Label^ Titulo2;
  private: System::Windows::Forms::TextBox^ txt_palabra;
  private: System::Windows::Forms::Button^ boton_usarAFD;
  private: System::Windows::Forms::Button^ boton_leerPalabra;
  private: System::Windows::Forms::Button^ boton_limpiarInfo;
  private: System::Windows::Forms::ComboBox^ comboBox_estadoInicial;

  private: System::Windows::Forms::ComboBox^ comboBox_estados;
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
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->txt_estadosFinales = (gcnew System::Windows::Forms::TextBox());
        this->txt_simbolosTransiciones = (gcnew System::Windows::Forms::TextBox());
        this->boton_transiciones = (gcnew System::Windows::Forms::Button());
        this->Titulo1 = (gcnew System::Windows::Forms::Label());
        this->Titulo2 = (gcnew System::Windows::Forms::Label());
        this->txt_palabra = (gcnew System::Windows::Forms::TextBox());
        this->boton_usarAFD = (gcnew System::Windows::Forms::Button());
        this->boton_leerPalabra = (gcnew System::Windows::Forms::Button());
        this->boton_limpiarInfo = (gcnew System::Windows::Forms::Button());
        this->comboBox_estadoInicial = (gcnew System::Windows::Forms::ComboBox());
        this->comboBox_estados = (gcnew System::Windows::Forms::ComboBox());
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
        this->out_textBox->Size = System::Drawing::Size(346, 335);
        this->out_textBox->TabIndex = 0;
        this->out_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::out_textBox_TextChanged);
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->Location = System::Drawing::Point(57, 63);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(125, 15);
        this->label1->TabIndex = 1;
        this->label1->Text = L"Cantidad de estados: ";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->Location = System::Drawing::Point(71, 100);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(80, 15);
        this->label2->TabIndex = 2;
        this->label2->Text = L"Estado Inicial";
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->Location = System::Drawing::Point(182, 101);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(94, 15);
        this->label3->TabIndex = 3;
        this->label3->Text = L"Estados Finales";
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->Location = System::Drawing::Point(303, 100);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(128, 15);
        this->label4->TabIndex = 4;
        this->label4->Text = L"Simbolos transiciones";
        // 
        // label5
        // 
        this->label5->AutoSize = true;
        this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->Location = System::Drawing::Point(57, 272);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(146, 15);
        this->label5->TabIndex = 5;
        this->label5->Text = L"Ingrese la palabra a leer: ";
        // 
        // txt_estadosFinales
        // 
        this->txt_estadosFinales->Enabled = false;
        this->txt_estadosFinales->ForeColor = System::Drawing::SystemColors::ScrollBar;
        this->txt_estadosFinales->Location = System::Drawing::Point(179, 122);
        this->txt_estadosFinales->Name = L"txt_estadosFinales";
        this->txt_estadosFinales->Size = System::Drawing::Size(100, 20);
        this->txt_estadosFinales->TabIndex = 7;
        this->txt_estadosFinales->Text = L"Ejemplo: 2,3,5";
        this->txt_estadosFinales->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->txt_estadosFinales->Enter += gcnew System::EventHandler(this, &Form1::txt_estadosFinales_Enter);
        this->txt_estadosFinales->Leave += gcnew System::EventHandler(this, &Form1::txt_estadosFinales_Leave);
        // 
        // txt_simbolosTransiciones
        // 
        this->txt_simbolosTransiciones->Enabled = false;
        this->txt_simbolosTransiciones->ForeColor = System::Drawing::SystemColors::ScrollBar;
        this->txt_simbolosTransiciones->Location = System::Drawing::Point(302, 122);
        this->txt_simbolosTransiciones->Name = L"txt_simbolosTransiciones";
        this->txt_simbolosTransiciones->Size = System::Drawing::Size(129, 20);
        this->txt_simbolosTransiciones->TabIndex = 8;
        this->txt_simbolosTransiciones->Text = L"Ejemplo: a,b,c";
        this->txt_simbolosTransiciones->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->txt_simbolosTransiciones->Enter += gcnew System::EventHandler(this, &Form1::txt_simbolos_transiciones_Enter);
        this->txt_simbolosTransiciones->Leave += gcnew System::EventHandler(this, &Form1::txt_simbolosTransiciones_Leave);
        // 
        // boton_transiciones
        // 
        this->boton_transiciones->Enabled = false;
        this->boton_transiciones->Location = System::Drawing::Point(173, 162);
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
        this->Titulo1->Location = System::Drawing::Point(46, 22);
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
        this->Titulo2->Location = System::Drawing::Point(119, 225);
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
        this->txt_palabra->Location = System::Drawing::Point(209, 271);
        this->txt_palabra->Name = L"txt_palabra";
        this->txt_palabra->Size = System::Drawing::Size(232, 20);
        this->txt_palabra->TabIndex = 12;
        this->txt_palabra->Text = L"Ejemplo: \"9\"";
        this->txt_palabra->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        // 
        // boton_usarAFD
        // 
        this->boton_usarAFD->Enabled = false;
        this->boton_usarAFD->Location = System::Drawing::Point(50, 314);
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
        this->boton_leerPalabra->Location = System::Drawing::Point(195, 314);
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
        this->boton_limpiarInfo->Location = System::Drawing::Point(338, 314);
        this->boton_limpiarInfo->Name = L"boton_limpiarInfo";
        this->boton_limpiarInfo->Size = System::Drawing::Size(118, 37);
        this->boton_limpiarInfo->TabIndex = 15;
        this->boton_limpiarInfo->Text = L"Limpiar Información";
        this->boton_limpiarInfo->UseVisualStyleBackColor = true;
        this->boton_limpiarInfo->Click += gcnew System::EventHandler(this, &Form1::boton_limpiarInfo_Click);
        // 
        // comboBox_estadoInicial
        // 
        this->comboBox_estadoInicial->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboBox_estadoInicial->Enabled = false;
        this->comboBox_estadoInicial->FormattingEnabled = true;
        this->comboBox_estadoInicial->Location = System::Drawing::Point(66, 121);
        this->comboBox_estadoInicial->Name = L"comboBox_estadoInicial";
        this->comboBox_estadoInicial->Size = System::Drawing::Size(91, 21);
        this->comboBox_estadoInicial->TabIndex = 16;
        // 
        // comboBox_estados
        // 
        this->comboBox_estados->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboBox_estados->FormattingEnabled = true;
        this->comboBox_estados->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
            L"1", L"2", L"3", L"4", L"5", L"6", L"7",
                L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22"
        });
        this->comboBox_estados->Location = System::Drawing::Point(209, 62);
        this->comboBox_estados->MaxLength = 2;
        this->comboBox_estados->Name = L"comboBox_estados";
        this->comboBox_estados->Size = System::Drawing::Size(232, 21);
        this->comboBox_estados->TabIndex = 17;
        this->comboBox_estados->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox_estados_SelectedIndexChanged);
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(886, 385);
        this->Controls->Add(this->comboBox_estados);
        this->Controls->Add(this->comboBox_estadoInicial);
        this->Controls->Add(this->boton_limpiarInfo);
        this->Controls->Add(this->boton_leerPalabra);
        this->Controls->Add(this->boton_usarAFD);
        this->Controls->Add(this->txt_palabra);
        this->Controls->Add(this->Titulo2);
        this->Controls->Add(this->Titulo1);
        this->Controls->Add(this->boton_transiciones);
        this->Controls->Add(this->txt_simbolosTransiciones);
        this->Controls->Add(this->txt_estadosFinales);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
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

private: System::Void comboBox_estados_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    int selectedIndex = comboBox_estados->SelectedIndex;

    if (selectedIndex >= 0) {
        //MessageBox::Show(String::Format("El indice seleccionado es {0}", selectedIndex+1));
        nodosYestados = gcnew array<int>(selectedIndex);
        comboBox_estadoInicial->Enabled = true;
        comboBox_estadoInicial->Items->Clear();
        comboBox_estadoInicial->Text = "";
        for (size_t i = 0; i <= selectedIndex; i++)
        {
            comboBox_estadoInicial->Items->Add(i);
        }
        txt_estadosFinales->Enabled = true;
        txt_estadosFinales->Text = "Ejemplo: 2,3,5";
        txt_estadosFinales->ForeColor = System::Drawing::SystemColors::ScrollBar;
        txt_simbolosTransiciones->Enabled = true;
        txt_simbolosTransiciones->Text = "Ejemplo: a,b,c";
        txt_simbolosTransiciones->ForeColor = System::Drawing::SystemColors::ScrollBar;
        boton_transiciones->Enabled = true;
        
    }
    else {
        comboBox_estadoInicial->Enabled = false;
        txt_estadosFinales->Enabled = false;
        txt_simbolosTransiciones->Enabled = false;
    }

}

private: System::Void boton_Transiciones_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ transiciones = txt_simbolosTransiciones->Text;
    String^ estadosFinales = txt_estadosFinales->Text;
    estadoInicial = comboBox_estadoInicial->SelectedIndex;

    array<String^>^ simbolos = transiciones->Split(',');
    for each (String^ simbolo in simbolos)
    {
        if (simbolo->Length == 1)
        {
            arregloSimbolos->Add(simbolo);
        }
        else
        {
            arregloSimbolos->Clear();
            MessageBox::Show(String::Format("Error de formato en simbolos transiciones."));
            return;
        }
    }
    int numero;
    array<String^>^ finales = estadosFinales->Split(',');
    for each (String^ nodo in finales)
    {
        if (Int32::TryParse(nodo, numero)) 
        {
            nodosYestados[numero] = 1;
        }
        else
        {
            arregloSimbolos->Clear();
            nodosYestados->Clear;
            MessageBox::Show(String::Format("Error de formato en estados finales."));
            return;
        }
    }
}

private: System::Void txt_estadosFinales_Enter(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadosFinales->Text == "Ejemplo: 2,3,5")
    {
        txt_estadosFinales->Text = "";
        txt_estadosFinales->ForeColor = System::Drawing::SystemColors::MenuText;
    }
}

private: System::Void txt_estadosFinales_Leave(System::Object^ sender, System::EventArgs^ e) {
    if (txt_estadosFinales->Text == "")
    {
        txt_estadosFinales->ForeColor = System::Drawing::SystemColors::ScrollBar;
        txt_estadosFinales->Text = "Ejemplo: 2,3,5";
    }
}

private: System::Void txt_simbolos_transiciones_Enter(System::Object^ sender, System::EventArgs^ e) {
    if (txt_simbolosTransiciones->Text == "Ejemplo: a,b,c") 
    {
        txt_simbolosTransiciones->Text = "";
        txt_simbolosTransiciones->ForeColor = System::Drawing::SystemColors::MenuText;
    } 
}

private: System::Void txt_simbolosTransiciones_Leave(System::Object^ sender, System::EventArgs^ e) {
    if(txt_simbolosTransiciones->Text == "")
    {
        txt_simbolosTransiciones->ForeColor = System::Drawing::SystemColors::ScrollBar;
        txt_simbolosTransiciones->Text = "Ejemplo: a,b,c";
    }
}

private: System::Void CheckButtonEnabled() {
    if (txt_estadosFinales->Text != "" && txt_simbolosTransiciones->Text != "" && comboBox_estadoInicial->SelectedIndex != -1) {
        boton_transiciones->Enabled = true;
    }
    else {
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

