/*************************************************************/
/*
 *  LoongArch64 assembler for TCC: directives only.
 *
 *  CONFIG_TCC_ASM is enabled so that tccasm.c assembles .S files made of
 *  directives and data (lib/atomic.S carries LoongArch code as .int
 *  words), but there is no instruction encoder: a mnemonic or inline
 *  asm statement is rejected with "asm not supported on LoongArch64 yet".
 */

#ifdef TARGET_DEFS_ONLY

#define NB_ASM_REGS 32

ST_FUNC void g(int c);
ST_FUNC void gen_le16(int c);
ST_FUNC void gen_le32(int c);

/*************************************************************/
#else
/*************************************************************/
#define USING_GLOBALS
#include "tcc.h"

/* ---- byte emission (tccasm.c directives) ---- */
ST_FUNC void g(int c)
{
    if (nocode_wanted)
        return;
    section_realloc(cur_text_section, ind + 1);
    cur_text_section->data[ind++] = c;
}

ST_FUNC void gen_le16(int c)
{
    g(c);
    g(c >> 8);
}

ST_FUNC void gen_le32(int c)
{
    gen_le16(c);
    gen_le16(c >> 16);
}

ST_FUNC void gen_expr32(ExprValue *pe)
{
    gen_le32(pe->v);
}

/* ---- instruction/inline-asm entry points: not implemented ---- */
ST_FUNC void asm_opcode(TCCState *s1, int token)
{
    tcc_error("asm not supported on LoongArch64 yet");
}

ST_FUNC int asm_parse_regvar(int t)
{
    tcc_error("asm not supported on LoongArch64 yet");
    return -1;
}

ST_FUNC void asm_clobber(uint8_t *clobber_regs, const char *str)
{
    tcc_error("asm not supported on LoongArch64 yet");
}

ST_FUNC void asm_compute_constraints(ASMOperand *operands, int nb_operands,
                                     int nb_outputs, const uint8_t *clobber_regs,
                                     int *pout_reg)
{
    tcc_error("asm not supported on LoongArch64 yet");
}

ST_FUNC void asm_gen_code(ASMOperand *operands, int nb_operands,
                          int nb_outputs, int is_output,
                          uint8_t *clobber_regs, int out_reg)
{
    tcc_error("asm not supported on LoongArch64 yet");
}

ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, int modifier)
{
    tcc_error("asm not supported on LoongArch64 yet");
}

/*************************************************************/
#endif /* TARGET_DEFS_ONLY */
