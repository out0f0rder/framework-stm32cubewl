/**
  ******************************************************************************
  * @file    ca_rsa_hal.h
  * @author  MCD Application Team
  * @brief   This file contains the RSA router includes and definitions of
  *          the Cryptographic API (CA) module to the HAL Cryptographic library.
  * @note    This file shall never be included directly by application but
  *          through the main header ca_hash.h
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CA_RSA_HAL_H
#define CA_RSA_HAL_H

#if !defined(CA_RSA_H)
#error "This file shall never be included directly by application but through the main header ca_rsa.h"
#endif /* CA_RSA_H */

/* Configuration defines -----------------------------------------------------*/

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RSA */
#if defined(CA_ROUTE_RSA) && ((CA_ROUTE_RSA & CA_ROUTE_MASK) == CA_ROUTE_HAL)
/* Includes ------------------------------------------------------------------*/

/* Defines ------------------------------------------------------------------*/
#define CA_RSA_REQUIRED_WORKING_BUFFER      4

/* Typedef ------------------------------------------------------------------*/
/**
  * @brief  Structure type for RSA public key
  */
typedef struct
{
  uint8_t  *pmModulus;    /*!< RSA Modulus */
  int32_t  mModulusSize;  /*!< Size of RSA Modulus */
  uint8_t  *pmExponent;   /*!< RSA Public Exponent */
  int32_t  mExponentSize; /*!< Size of RSA Public Exponent */
}
CA_RSApubKey_stt;

/**
  * @brief  Structure type for RSA private key
  */
typedef struct
{
  uint8_t  *pmModulus; /*!< RSA Modulus */
  int32_t  mModulusSize; /*!< Size of RSA Modulus */
  uint8_t  *pmExponent; /*!< RSA Private Exponent */
  int32_t  mExponentSize; /*!< Size of RSA Private Exponent */
}
CA_RSAprivKey_stt;

/* Exported functions -------------------------------------------------------*/
#if (CA_ROUTE_RSA & CA_ROUTE_RSA_CFG_SIGN_ENABLE)
int32_t CA_RSA_PKCS1v15_Sign(const CA_RSAprivKey_stt *P_pPrivKey, const uint8_t *P_pDigest, CA_hashType_et P_hashType,
                             uint8_t *P_pSignature, CA_membuf_stt *P_pMemBuf);
#endif /* (CA_ROUTE_RSA & CA_ROUTE_RSA_CFG_SIGN_ENABLE) */

#if (CA_ROUTE_RSA & CA_ROUTE_RSA_CFG_VERIFY_ENABLE)
int32_t CA_RSA_PKCS1v15_Verify(const CA_RSApubKey_stt *P_pPubKey, const uint8_t *P_pDigest, CA_hashType_et P_hashType,
                               const uint8_t *P_pSignature, CA_membuf_stt *P_pMemBuf);
#endif /* (CA_ROUTE_RSA & CA_ROUTE_RSA_CFG_VERIFY_ENABLE) */
#endif /* (CA_ROUTE_RSA & CA_ROUTE_MASK) == CA_ROUTE_HAL */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< RSA */


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* CA_RSA_HAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

