#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED



#endif // VALIDATIONS_H_INCLUDED
/** \brief verifica que sean solo letras o espacios, si comienza en espacio lo toma como invalido
 *
 * \param inputStr - el puntero a char a verificar
 * \param lenght - la cantidad de caracteres
 * \return 1 si es valido - 0 si no es valido
 *
 */
int isName (char* inputStr , int lenght)
/** \brief verifica que sean solo digitos
 *
 * \param inputStr - el puntero a char a verificar
 * \param lenght - la cantidad de caracteres
 * \return 1 si es valido - 0 si no es valido
 *
 */
int isInt (char* inputStr , int lenght)
