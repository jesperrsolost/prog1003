/**
 *  Overloaded funksjon som skriver en structs data (peker som parameter).
 *
 *  @param   bok  - PEKER til structen hvis data utskrives p� skjermen
 */
void bokSkrivData(const Bok* bok)  {
   cout << "\t\t\"" << bok->tittel << "\" av " << bok->forfatter
        << ",  " << bok->antallSider << " sider - "
        << ((!bok->lest) ? "IKKE " : "") << "lest\n";
}