enum addressing_mode {
    AM_A,
    AM_abs,
    AM_abs_X,
    AM_abs_Y,
    AM_imm,
    AM_impl,
    AM_ind,
    AM_X_ind,
    AM_ind_Y,
    AM_rel,
    AM_zpg,
    AM_zpg_X,
    AM_zpg_Y,
    AM_NONEXIST,
};
typedef struct cpu_state {
    uint16_t ip;
    uint8_t accum;
    uint8_t X;
    uint8_t Y;
    uint8_t status;
} cpu_state_t;